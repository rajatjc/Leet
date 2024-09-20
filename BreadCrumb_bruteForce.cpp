#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <map>

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

    double volume = std::abs(scalar_triple_product) / 6.0;
    return volume;
}

std::vector<Point> read_points(const std::string& file_path) {
    std::vector<Point> points;
    std::ifstream infile(file_path);
    std::string line;
    while (std::getline(infile, line)) {
        Point p;
        sscanf(line.c_str(), "(%lf,%lf,%lf,%d)", &p.x, &p.y, &p.z, &p.n);
        points.push_back(p);
    }
    return points;
}

std::vector<int> find_smallest_tetrahedron(const std::vector<Point>& points) {
    double min_volume = std::numeric_limits<double>::infinity();
    std::vector<int> best_combination;

    int n = points.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    const Point& p1 = points[i];
                    const Point& p2 = points[j];
                    const Point& p3 = points[k];
                    const Point& p4 = points[l];

                    if (p1.n + p2.n + p3.n + p4.n == 100) {
                        double vol = volume_of_tetrahedron(p1, p2, p3, p4);
                        if (vol < min_volume) {
                            min_volume = vol;
                            best_combination = {i, j, k, l};
                        }
                    }
                }
            }
        }
    }
    return best_combination;
}

std::map<int, int> count_n_values(const std::vector<Point>& points) {
    std::map<int, int> n_counts;
    for (const Point& p : points) {
        n_counts[p.n]++;
    }
    return n_counts;
}

int main() {
    // Read and process points_small.txt
    std::vector<Point> points_small = read_points("points_small.txt");
    std::vector<int> small_indices = find_smallest_tetrahedron(points_small);

    // Count n values for points_small.txt
    std::map<int, int> n_counts_small = count_n_values(points_small);

    // Print the map of n values and their counts for points_small.txt
    std::cout << "n values and their counts for points_small.txt:" << std::endl;
    for (const auto& pair : n_counts_small) {
        std::cout << "n: " << pair.first << ", count: " << pair.second << std::endl;
    }

    // Read and process points_large.txt
    std::vector<Point> points_large = read_points("points_large.txt");
    // std::vector<int> large_indices = find_smallest_tetrahedron(points_large);

    // Count n values for points_large.txt
    std::map<int, int> n_counts_large = count_n_values(points_large);

    // Print the map of n values and their counts for points_large.txt
    std::cout << "n values and their counts for points_large.txt:" << std::endl;
    for (const auto& pair : n_counts_large) {
        std::cout << "n: " << pair.first << ", count: " << pair.second << std::endl;
    }

    // Output the results
    std::cout << "Indices for points_small.txt: ";
    for (int index : small_indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // std::cout << "Indices for points_large.txt: ";
    // for (int index : large_indices) {
    //     std::cout << index << " ";
    // }
    std::cout << std::endl;

    return 0;
}
