class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 1;

        // dp[i][mod] = max length ending at i with modulo mod
        vector<unordered_map<int, int>> dp(n);

        for(int i = 0; i < n; ++i) {
            dp[i] = unordered_map<int, int>();

            for(int j = 0; j < i; ++j) {
                int mod = (nums[i] + nums[j]) % k;
                int prevLen = dp[j].count(mod) ? dp[j][mod] : 1;
                dp[i][mod] = max(dp[i][mod], prevLen + 1);
                maxLen = max(maxLen, dp[i][mod]);
            }
        }

        return maxLen;
    }
};
