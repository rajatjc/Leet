#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX

using namespace std;

// Function to find the minimum energy required to reach the nth stair
int minEnergy(const vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;

    // Base case: if there's only one step
    if (n == 1) return 0;

    // dp array to store minimum energy to reach each step
    vector<int> dp(n, INT_MAX);

    // Initial step
    dp[0] = 0;

    // Compute the minimum energy for each step
    for (int i = 0; i < n; ++i) {
        // Jump to i+1
        if (i + 1 < n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(heights[i] - heights[i + 1]));
        }
        // Jump to i+2
        if (i + 2 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(heights[i] - heights[i + 2]));
        }
    }

    // The answer is the minimum energy required to reach the last step
    return dp[n - 1];
}

int main() {
    // Example input
    vector<int> heights = {10, 20, 30, 10};

    cout << "Minimum energy required: " << minEnergy(heights) << endl;

    return 0;
}
 