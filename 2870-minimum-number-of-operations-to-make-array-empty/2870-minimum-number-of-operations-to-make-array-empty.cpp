class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        // Count the frequency of each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int result = 0;

        // Traditional for loop to go through the map
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int freq = it->second;

            if (freq == 1) return -1;

            result += ceil((double)freq/3);
        }

        return result;
    }
};
