#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, int k, vector<int>& a, vector<int>& b) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; ++i) {
        int max_prev = 0;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            max_prev = max(max_prev, dp[i - 1][j - 1] - b[j - 1]);
            dp[i][j] = max(dp[i][j], max_prev + a[j - 1]);
        }
    }

    return dp[k][n];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int result = solve(n, k, a, b);
        cout << result << endl;
    }

    return 0;
}
