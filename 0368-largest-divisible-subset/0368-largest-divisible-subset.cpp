class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());  // Step 1: Sort the array

        int n = nums.size();
        vector<int> dp(n, 1);  // DP array to store the size of largest divisible subset
        vector<int> prev(n, -1);  // To reconstruct the subset
        int maxSize = 1, maxIndex = 0;

        // Step 2: Fill the DP and prev arrays
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        // Step 3: Reconstruct the largest divisible subset
        vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        
        reverse(result.begin(), result.end());  // Reverse to get the correct order
        return result;
    }
};
