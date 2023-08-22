#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int left = 0;
        int maxLen = 0;
        int maxFrequency = 0;  // Track the maximum frequency directly

        unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;

            maxFrequency = max(maxFrequency, freq[nums[right]]);

            // Calculate the size of the window and check if it's valid
            int windowSize = right - left + 1;
            int deletionsNeeded = windowSize - maxFrequency;

            // If deletions needed are more than allowed, shrink the window
            if (deletionsNeeded > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            // Update the maximum length
            maxLen = max(maxLen, maxFrequency);
        }

        return maxLen;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1,1,2,3,4,5,1,1};
    int k = 2;

    int result = solution.longestEqualSubarray(nums, k);
    cout << "Longest equal subarray length: " << result << endl;

    return 0;
}
