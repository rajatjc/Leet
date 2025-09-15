class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> prefixSumCount;  // Store the frequency of prefix sums modulo modulo
        int prefixSum = 0;
        long long count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%modulo==k)
                nums[i]=1;
            else
                nums[i]=0;
        }
        // Initialize the frequency of prefix sum 0 as 1 (empty subarray)
        prefixSumCount[0] = 1;

        for (int num : nums) {
            prefixSum = (prefixSum + num) % modulo;  // Calculate the prefix sum modulo modulo

            // Calculate the complement needed to reach k modulo modulo
            int complement = (prefixSum - k + modulo) % modulo;

            // Update the count with the frequency of the complement if it exists
            count += prefixSumCount[complement];

            // Update the frequency of the current prefix sum modulo modulo
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};
