class Solution {
public:
    // DP table: t[i][j] stores minimum insertions needed for substring s[i..j]
    int t[501][501];

    // Recursive function to compute minimum insertions for s[i..j]
    int solve(int i, int j, string &s) {
 
        // Base case: If string is empty (i > j) or has 1 character (i == j), no insertions needed
        if(i >= j)
            return 0;
        
        // If already solved, return stored result (memoization)
        if(t[i][j] != -1)
            return t[i][j];
        
        // If first and last characters match, check the inside substring (i+1 .. j-1)
        if(s[i] == s[j])
            return t[i][j] = solve(i+1, j-1, s);
        
        // If characters don’t match:
        // We must insert one character, either matching s[j] before i, or s[i] after j.
        // Take the minimum of both options + 1 insertion.
        return t[i][j] = 1 + min(solve(i, j-1, s), solve(i+1, j, s));
        
    }
    
    // Main function: returns minimum insertions to make s a palindrome
    int minInsertions(string s) {
        int n = s.length();  // Length of input string
        
        // Initialize DP table with -1 (uncomputed states)
        memset(t, -1, sizeof(t));
        
        // Solve the problem for the full string s[0..n-1]
        return solve(0, n-1, s);
    }
};
