class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;

        // Count frequency of each number
        for (int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }

        int lucky = -1;

        // Find the largest lucky number
        for (auto& it : mp) {
            if (it.first == it.second) {
                lucky = max(lucky, it.first);
            }
        }

        return lucky;
    }
};
