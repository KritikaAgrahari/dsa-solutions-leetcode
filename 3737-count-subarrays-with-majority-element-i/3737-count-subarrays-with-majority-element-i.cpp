class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();      // Size of the array
        int ans = 0;              // Stores the final answer

        // Choose the starting index of the subarray
        for(int i = 0; i < n; i++)
        {
            int count = 0;        // Count of target in current subarray

            // Extend the subarray one element at a time
            for(int j = i; j < n; j++)
            {
                // If current element is target, increase its count
                if(nums[j] == target)
                    count++;

                // Length of current subarray
                int length = j - i + 1;

                // Check if target is the majority element
                if(count > length / 2)
                    ans++;
            }
        }

        // Return total valid subarrays
        return ans;
    }
};