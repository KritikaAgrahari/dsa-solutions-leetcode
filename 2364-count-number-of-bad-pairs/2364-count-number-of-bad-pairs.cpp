class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();  
        
        long long result = 0;  
        unordered_map<int, int> mp;  // Hash map to store frequency of (nums[i] - i)

        // Loop through each element in the array
        for(int i = 0; i < n; i++) {
            int diff = nums[i] - i;  // Calculate the value of nums[i] - i

            // At index 'i', the total number of pairs formed is equal to i
            int totalPairsTillIndex = i;

            // 'goodPairs' counts how many previous elements have the same 'diff'
            // These form "good pairs" because nums[j] - j == nums[i] - i
            int goodPairs = mp[diff];

            // Subtract goodPairs from totalPairsTillIndex to get the number of bad pairs involving nums[i]
            result += (totalPairsTillIndex - goodPairs);

            // Update the frequency of the current 'diff' in the map
            mp[diff]++;
        }

        return result;  // Return the total count of bad pairs
    }
};
