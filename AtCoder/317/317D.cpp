#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class District {
public:
    int x, y, z;

    District(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};


long long minimize_subset_sum(vector<int>& A, vector<int>& weights, int x) {
    int n = A.size();
    int max_weight = 0;
    for (int w : weights) {
        max_weight += w;
    }
    
    vector<vector<long long>> dp(n + 1, vector<long long>(max_weight + 1, 1e15));
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= max_weight; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - weights[i - 1]] + A[i - 1]);
            }
        }
    }
    
    long long result = 1e15;
    for (int j = x + 1; j <= max_weight; ++j) {
        result = min(result, dp[n][j]);
    }
    
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<District> districts;

    int totalSeats = 0;
    for (int i = 0; i < N; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        districts.emplace_back(x, y, z);
        totalSeats += z;
    }

    int halfTotalSeats = totalSeats / 2;

    vector<pair<int, int>> votersToChangeAndWeight;

    for (int i = 0; i < N; ++i) {
        if (districts[i].y > districts[i].x) {
            int votersNeeded = ceil((districts[i].y - districts[i].x) / 2.0);
            votersToChangeAndWeight.emplace_back(votersNeeded, districts[i].z);
        } else {
            votersToChangeAndWeight.emplace_back(0, districts[i].z);
        }
    }

    vector<int> A, weights;
    for (const auto& item : votersToChangeAndWeight) {
        A.push_back(item.first);
        weights.push_back(item.second);
    }

    long long result = minimize_subset_sum(A, weights, halfTotalSeats);

    cout << result << endl;

    return 0;
}
