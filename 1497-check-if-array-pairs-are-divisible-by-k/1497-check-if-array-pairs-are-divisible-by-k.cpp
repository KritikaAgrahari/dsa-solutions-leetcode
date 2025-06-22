class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0);

        // Count frequency of each remainder
        for (int i = 0; i < arr.size(); i++) {
            int rem = (arr[i] % k + k) % k;
            mp[rem]++;
        }

        // Remainder 0 must be even
        if (mp[0] % 2 != 0) return false;

        // Check pairs of remainders
        for (int rem = 1; rem < k; rem++) {
            if (mp[rem] != mp[k - rem]) return false;
        }

        return true;
    }
};
