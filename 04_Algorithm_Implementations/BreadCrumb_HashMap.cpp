#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <set>
#include <tuple>
#include <algorithm>
#include <sstream>

using namespace std;

struct Point {
    double x, y, z;
    int n;
    int original_index; // Store the original index
};
bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y < b.y;
    return a.z < b.z;
}
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

    double volume = std::abs(scalar_triple_product) / 6.0;
    return volume;
}

vector<Point> read_points(const string& file_path) {
    vector<Point> points;
    ifstream infile(file_path);
    string line;
    int index = 0;
    while (getline(infile, line)) {
        Point p;
        replace(line.begin(), line.end(), '(', ' ');
        replace(line.begin(), line.end(), ')', ' ');
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        ss >> p.x >> p.y >> p.z >> p.n;
        p.original_index = index++; // Store the original index
        points.push_back(p);
    }
    return points;
}

vector<int> find_smallest_tetrahedron(const vector<Point>& points) {
    int n = points.size();
    unordered_multimap<int, pair<int, int>> sumPairs;
    set<tuple<int, int, int, int>> results;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = points[i].n + points[j].n;
            sumPairs.insert({sum, {i, j}});
        }
    }

    double min_volume = numeric_limits<double>::infinity();
    vector<int> best_combination;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int currentSum = points[i].n + points[j].n;
            int remainingSum = 100 - currentSum;

            auto range = sumPairs.equal_range(remainingSum);
            for (auto it = range.first; it != range.second; ++it) {
                pair<int, int> p = it->second;

                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    vector<int> indices = {i, j, p.first, p.second};
                    sort(indices.begin(), indices.end());
                    results.insert({indices[0], indices[1], indices[2], indices[3]});
                    const Point& p1 = points[indices[0]];
                    const Point& p2 = points[indices[1]];
                    const Point& p3 = points[indices[2]];
                    const Point& p4 = points[indices[3]];

                    double vol = volume_of_tetrahedron(p1, p2, p3, p4);
                    if (vol < min_volume) {
                        min_volume = vol;
                        best_combination = {indices[0], indices[1], indices[2], indices[3]};

                        // Print the original indices and details of the points
                        cout << "\nNew minimum volume found: " << min_volume << endl;
                        cout << "Original Indices: " 
                             << points[indices[0]].original_index << " "
                             << points[indices[1]].original_index << " "
                             << points[indices[2]].original_index << " "
                             << points[indices[3]].original_index << endl;
                        // cout << "Points details:" << endl;
                        // cout << points[indices[0]].x << " " << points[indices[0]].y << " " << points[indices[0]].z << " " << points[indices[0]].n << endl;
                        // cout << points[indices[1]].x << " " << points[indices[1]].y << " " << points[indices[1]].z << " " << points[indices[1]].n << endl;
                        // cout << points[indices[2]].x << " " << points[indices[2]].y << " " << points[indices[2]].z << " " << points[indices[2]].n << endl;
                        // cout << points[indices[3]].x << " " << points[indices[3]].y << " " << points[indices[3]].z << " " << points[indices[3]].n << endl;
                    }
                }
            }
        }
    }

    return best_combination;
}

int main() {
    cout << "==============Reading Points Small==================";
    
    vector<Point> points = read_points("points_small.txt");
    sort(points.begin(), points.end(), comparePoints);

    vector<int> indices = find_smallest_tetrahedron(points);

    // Print the original indices for points_small.txt
    cout << "Original Indices for points_small.txt: ";
    for (int index : indices) {
        cout << points[index].original_index << " ";
    }
    cout << endl;

cout << "==============Reading Points Large==================";
    
    points = read_points("points_large.txt");
    sort(points.begin(), points.end(), comparePoints);

    indices = find_smallest_tetrahedron(points);

    // Print the original indices for points_large.txt
    cout << "Original Indices for points_large.txt: ";
    for (int index : indices) {
        cout << points[index].original_index << " ";
    }
    cout << endl;

    return 0;
}
