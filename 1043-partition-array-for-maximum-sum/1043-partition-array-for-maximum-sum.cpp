class Solution {
public:
    int n;                // To store the size of the input array
    int t[501];           // DP table: t[idx] = maximum sum achievable starting from index idx

    // Recursive function with memoization
    int solve(vector<int>& arr, int idx, int k) {
        // Base case: if we go out of bounds, no contribution
        if(idx >= n) {
            return 0;
        }
        
        // If result already computed, reuse it (memoization)
        if(t[idx] != -1) {
            return t[idx];
        }
        
        int result = 0;       // Best result from this position
        int curr_max = -1;    // Track maximum element in the current partition
        
        // Try all partitions starting at 'idx', up to length k
        for(int i = idx; i < n && i-idx+1 <= k; i++) {
            // Update maximum element in this partition
            curr_max = max(curr_max, arr[i]);
            
            // Length of current partition = (i - idx + 1)
            // Contribution = curr_max * partition length
            // Then recursively solve for the rest (i+1 onwards)
            result = max(result, curr_max*(i-idx+1) + solve(arr, i+1, k));
        }
        
        // Store and return the best result
        return t[idx] = result;
    }
    
    // Main function
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();              // Store size of array
        memset(t, -1, sizeof(t));    // Initialize DP table with -1 (uncomputed)
        return solve(arr, 0, k);     // Start solving from index 0
    }
};
