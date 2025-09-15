class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        vector<int> flag(5, -1); // Initialize flags to -1, indicating not found.
        vector<vector<int>> index(5, vector<int>(2, -1)); // Initialize index with size 4x2.

        for (int i = n - 1; i >= 0; i--) {
            char digit = num[i];
            if (digit == '0' && flag[0] == -1) {
                flag[0] = 1;
                index[0][0] = i;
            } else if (digit == '0' && flag[0] == 1) {
                flag[0] = 2;
                index[0][1] = i;
            }
        }
        

        for (int i = n - 1; i >= 0; i--) {
            char digit = num[i];
            if (digit == '5' && flag[1] == -1) {
                flag[1] = 1;
                index[1][0] = i;
            } else if (digit == '2' && flag[1] == 1) {
                flag[1] = 2;
                index[1][1] = i;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            char digit = num[i];
            if (digit == '0' && flag[2] == -1) {
                flag[2] = 1;
                index[2][0] = i;
            } else if (digit == '5' && flag[2] == 1) {
                flag[2] = 2;
                index[2][1] = i;
            }
        }

        
          for (int i = n - 1; i >= 0; i--) {
            char digit = num[i];
            if (digit == '5' && flag[3] == -1) {
                flag[3] = 1;
                index[3][0] = i;
            } else if (digit == '7' && flag[3] == 1) {
                flag[3] = 2;
                index[3][1] = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            char digit = num[i];
            if (digit == '0') {
                flag[4] = 2;
                index[4][0] = i;
                index[4][1] = i;
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < 4; i++) {
            if (flag[i] == 2) {
                // cout<<i<<endl;
                // cout<<index[i][0]<<" "<<index[i][1]<<endl;
                ans = min(ans, n - index[i][1] - 2);
            }
        }
        if (flag[4] == 2)
            ans = min(ans, n - 1);

        return (ans == INT_MAX) ? n : ans;
    }
};
