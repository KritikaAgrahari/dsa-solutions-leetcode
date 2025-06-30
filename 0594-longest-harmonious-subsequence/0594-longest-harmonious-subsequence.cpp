class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp; // Map to store frequency of each number

        int result = 0; // Variable to store the maximum length of harmonious subsequence

        // First loop to count frequency of each number
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++; // Increment count for nums[i]
        }

        // Second loop to find the longest harmonious subsequence
        for(int i = 0; i < nums.size(); i++) {
            int minNum = nums[i];      // Current number
            int maxNum = nums[i] + 1;  // Number that should differ by exactly 1

            // Check if maxNum exists in the map
            if(mp.count(maxNum)) {
                // Update result if the sum of frequencies is greater
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }

        return result; // Return the maximum length found
    }
};
