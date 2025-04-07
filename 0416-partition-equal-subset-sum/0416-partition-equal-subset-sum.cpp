class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, we can't split into two equal subsets
        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        int n = nums.size();

        // dp[i] means whether we can get sum i using the numbers
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: 0 sum is always possible

        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
