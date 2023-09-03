class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long maxSum = 0;
        unordered_map<int, int> elementCount; // Stores count of each element in the window
        
        for (int i = 0; i < k; ++i) {
            elementCount[nums[i]]++;
        }
        
        int distinctCount = elementCount.size();
        if (distinctCount >= m) {
            long long windowSum = 0;
            for (int i = 0; i < k; ++i) {
                windowSum += nums[i];
            }
            maxSum = windowSum;
        }
        
        for (int i = k; i < n; ++i) {
            // Remove the leftmost element from the window
            int leftElement = nums[i - k];
            if (elementCount[leftElement] == 1) {
                elementCount.erase(leftElement);
                distinctCount--;
            } else {
                elementCount[leftElement]--;
            }
            
            // Add the current element to the window
            int rightElement = nums[i];
            elementCount[rightElement]++;
            if (elementCount[rightElement] == 1) {
                distinctCount++;
            }
            
            // Check if the window contains at least m distinct elements
            if (distinctCount >= m) {
                long long windowSum = 0;
                for (int j = i - k + 1; j <= i; ++j) {
                    windowSum += nums[j];
                }
                maxSum = max(maxSum, windowSum);
            }
        }
        
        return maxSum;
    }
};
