class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& t) {
        if(i == m-1 && j == n-1) {
            return 1; 
            // ✅ Base case: reached bottom-right cell → 1 valid path found
        }

        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 0; 
            // Out of grid boundaries → no valid path
        }

        if(t[i][j] != -1) {
            return t[i][j]; 
            //  Already computed → return stored result (memoization)
        }

        int right = solve(i, j+1, m, n, t); 
        // ➡ Move right to (i, j+1)

        int down  = solve(i+1, j, m, n, t); 
        // ⬇ Move down to (i+1, j)

        return t[i][j] = right + down; 
        //  Total paths from (i, j) = paths by moving right + moving down
        // Store in DP table to avoid recomputation
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, -1)); 
        // DP table initialized with -1 (for memoization)

        return solve(0, 0, m, n, t); 
        // Start from top-left (0,0)
    }
};
