class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;  // Initialize the result to count the number of good pairs

        unordered_map<int, int> mp;  // Hash map to store frequency of each number

        // Loop through the array using traditional index-based for loop
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];         // Get the current number
            result += mp[num];         // Add how many times we've already seen this number
            mp[num]++;                 // Increment the count of this number in the map
        }

        return result;  // Return the total number of good (i, j) pairs where nums[i] == nums[j] and i < j
    }
};
