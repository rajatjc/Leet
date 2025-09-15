class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1, 0); // dp[i] represents the maximum gold from houses 0 to i
        
        // Sort offers by end position
        sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int offerIndex = 0; // Index to keep track of the current offer being considered
        
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1]; // If not selling the current house
            
            while (offerIndex < offers.size() && offers[offerIndex][1] == i - 1) {
                int start = offers[offerIndex][0], gold = offers[offerIndex][2];
                dp[i] = max(dp[i], dp[start] + gold); // If selling the current house with offer
                ++offerIndex;
            }
        }
        
        return dp[n];
    }
};
