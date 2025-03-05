class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; i++)
            power[i] = (power[i - 1] * 2) % MOD;  // Precompute powers of 2

        int l = 0, r = n - 1, count = 0;
        
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                count = (count + power[r - l]) % MOD;  // Count valid subsequences
                l++;  // Move left pointer
            } else {
                r--;  // Move right pointer
            }
        }
        return count;
    }
};
