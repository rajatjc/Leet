class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Step 1
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int count = 0;

        while (left < right) { // Step 4
            if (nums[left] + nums[right] < target) { // Step 4a
                count += right - left;
                left++; // Step 4b
            } else {
                right--; // Step 4c
            }
        }

        return count; // Step 5
    }
};
