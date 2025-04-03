class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];

        for (int i = 1; i < n; ++i)
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);

        long long maxValue = 0;
        int maxK = nums[n - 1];

        for (int j = n - 2; j > 0; --j) {
            maxK = max(maxK, nums[j + 1]);
            long long tripletValue = (long long)(prefixMax[j - 1] - nums[j]) * maxK;
            maxValue = max(maxValue, tripletValue);
        }

        return maxValue;
    }
};
