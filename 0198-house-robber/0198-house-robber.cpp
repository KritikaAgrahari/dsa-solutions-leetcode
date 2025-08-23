class Solution {
public:
    int t[101];  
    // Array used for memoization (stores already computed results for indices up to 100)

    int solve(vector<int>& nums, int i, int& n) {
        if(i >= n)
            return 0;  
        // Base case: if index goes beyond the last house, we can’t rob anything → return 0

        if(t[i] != -1)
            return t[i];  
        // If the result for this index is already computed, return it (avoid recomputation)

        int take = nums[i] + solve(nums, i+2, n);  
        // Option 1: Rob the current house (add its money)  
        // → Skip the adjacent house → move to i+2

        int skip = solve(nums, i+1, n);  
        // Option 2: Skip the current house  
        // → Move to the next house (i+1)

        return t[i] = max(take, skip);  
        // Store and return the maximum profit between "take" and "skip"
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();  
        // Total number of houses

        memset(t, -1, sizeof(t));  
        // Initialize memoization array with -1 (meaning "not yet computed")

        return solve(nums, 0, n);  
        // Start recursion from the 0th house
    }
};
