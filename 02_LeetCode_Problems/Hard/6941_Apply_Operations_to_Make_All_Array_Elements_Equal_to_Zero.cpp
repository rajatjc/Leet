class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] >= nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        int maxLength = *max_element(LIS.begin(), LIS.end());
        int minChanges = n - maxLength;

        return minChanges;
    }
};
