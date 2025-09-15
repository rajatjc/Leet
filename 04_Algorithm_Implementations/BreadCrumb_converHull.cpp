#include<bits/stdc++.h>

using namespace std;

struct Point {
    double x, y, z;
    int n;
};

double volume_of_tetrahedron(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    double ABx = p2.x - p1.x, ABy = p2.y - p1.y, ABz = p2.z - p1.z;
    double ACx = p3.x - p1.x, ACy = p3.y - p1.y, ACz = p3.z - p1.z;
    double ADx = p4.x - p1.x, ADy = p4.y - p1.y, ADz = p4.z - p1.z;

    double cross_product_x = ABy * ACz - ABz * ACy;
    double cross_product_y = ABz * ACx - ABx * ACz;
    double cross_product_z = ABx * ACy - ABy * ACx;

    double scalar_triple_product = 
        ADx * cross_product_x + 
        ADy * cross_product_y + 
        ADz * cross_product_z;

    double volume = abs(scalar_triple_product) / 6.0;
    return volume;
}

vector<Point> read_points(const string& file_path) {
    vector<Point> points;
    ifstream infile(file_path);
    string line;
    while (getline(infile, line)) {
        Point p;
        replace(line.begin(), line.end(), '(', ' ');
        replace(line.begin(), line.end(), ')', ' ');
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        ss >> p.x >> p.y >> p.z >> p.n;
        // cout<< p.x <<" "<< p.y <<" "<< p.z <<" "<< p.n<<endl;
        points.push_back(p);
    }
    // cout<<points.size()<<endl;

    return points;
}

struct Face {
    int a, b, c;
    Face(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

vector<Face> faces;

double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

void add_face(int a, int b, int c) {
    if (a != b && b != c && a != c) {
        faces.push_back(Face(a, b, c));
    }
}

void build_faces(vector<Point>& points, int a, int b, int c) {
    int sign = 0;
    double side;
    for (int i = 0; i < points.size(); ++i) {
        if (i != a && i != b && i != c) {
            side = (points[i].x - points[a].x) * ((points[b].y - points[a].y) * (points[c].z - points[a].z) - (points[c].y - points[a].y) * (points[b].z - points[a].z)) +
                   (points[i].y - points[a].y) * ((points[b].z - points[a].z) * (points[c].x - points[a].x) - (points[c].z - points[a].z) * (points[b].x - points[a].x)) +
                   (points[i].z - points[a].z) * ((points[b].x - points[a].x) * (points[c].y - points[a].y) - (points[c].x - points[a].x) * (points[b].y - points[a].y));
            if (sign == 0) {
                sign = side > 0 ? 1 : -1;
            } else {
                if (side > 0 && sign == -1) {
                    return;
                } else if (side < 0 && sign == 1) {
                    return;
                }
            }
        }
    }
    add_face(a, b, c);
}

void build_hull(vector<Point>& points, int a, int b, int c) {
    build_faces(points, a, b, c);
    build_faces(points, b, c, a);
    build_faces(points, c, a, b);
}

void quick_hull(vector<Point>& points, int a, int b, int c) {
    if (points.empty()) {
        return;
    }

    double max_dist = -numeric_limits<double>::infinity();
    int farthest_point = -1;

    for (int i = 0; i < points.size(); ++i) {
        if (i != a && i != b && i != c) {
            double d = dist(points[i], points[a]);
            if (d > max_dist) {
                max_dist = d;
                farthest_point = i;
            }
        }
    }

    if (farthest_point == -1) {
        build_hull(points, a, b, c);
        return;
    }

    quick_hull(points, farthest_point, a, b);
    quick_hull(points, farthest_point, b, c);
    quick_hull(points, farthest_point, c, a);
}

vector<int> find_smallest_tetrahedron(const vector<Point>& points) {
    vector<int> indices;
    if (points.size() < 4) {
        return indices; // Not enough points to form a tetrahedron
    }

    quick_hull(points, 0, 1, 2);

    double min_volume = numeric_limits<double>::infinity();

    for (const auto& face : faces) {
        const Point& p1 = points[face.a];
        const Point& p2 = points[face.b];
        const Point& p3 = points[face.c];
        for (int i = 0; i < points.size(); ++i) {
            if (i != face.a && i != face.b && i != face.c) {
                double vol = volume_of_tetrahedron(p1, p2, p3, points[i]);
                if (vol < min_volume && p1.n + p2.n + p3.n + points[i].n == 100) {
                    min_volume = vol;
                    indices.push_back(face.a);
                    indices.push_back(face.b);
                    indices.push_back(face.c);
                    indices.push_back(i);
                }
            }
        }
    }

    return indices;
}

int main() {
    vector<Point> points = read_points("points_small.txt");
    vector<int> indices = find_smallest_tetrahedron(points);

    cout << "Indices for points.txt: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
