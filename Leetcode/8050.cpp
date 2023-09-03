#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, string q) {
        int m = s.length();
        int n = q.length();
        
        // Create a 2D DP array to store the count of subsequences with the same character frequencies.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Initialize the first row with 1's because an empty string has the same frequencies as an empty string.
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
        // Fill the DP array based on character frequencies.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == q[j - 1]) {
                    // If the characters match, we have two options:
                    // 1. Include the current character in both strings.
                    // 2. Exclude the current character from both strings.
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // If characters don't match, we can only exclude the current character
                    // from both strings.
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    string s = "abbcd";
    string q = "abcd";
    
    Solution solution;
    int result = solution.countKSubsequencesWithMaxBeauty(s, q);
    
    cout << "Count of subsequences with the same character frequencies as 'bacd' in 'abbcd': " << result << endl;
    
    return 0;
}
