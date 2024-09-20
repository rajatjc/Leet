// #include <iostream>
// #include <vector>
// using namespace std;

// int fib(int n, vector<int>& dp) {
//     if (n <= 1) return n;
//     if (dp[n] != -1) return dp[n];
//     dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
//     return dp[n];
// }

// int main() {
//     int n = 5; // Example input
//     vector<int> dp(n + 1, -1); // Initialize DP array with -1
//     cout << "Fibonacci of " << n << " is " << fib(n, dp) << endl;
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    if (n > 0) dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 5; // Example input
    cout << "Fibonacci of " << n << " is " << fib(n) << endl;
    return 0;
}
