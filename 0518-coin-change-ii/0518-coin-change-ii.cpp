class Solution {
public:
    int n;  
    // Stores number of coin types
    
    int t[301][5001];  
    // DP memo table: 
    // t[i][amount] = number of ways to make "amount" using coins from index i to n-1
    // Constraints: max 300 coins, amount up to 5000

    int solve(int i, vector<int>& coins, int amount) {
        
        if(amount == 0)
            return t[i][amount] = 1;  
            // ✅ Base case: If amount is 0, we found a valid combination → return 1 way
        
        if(i == n || amount < 0)
            return 0;  
            // ❌ If no coins left (i==n) or amount goes negative → no way
        
        if(t[i][amount] != -1)
            return t[i][amount];  
            // \U0001f504 If already computed, return stored result (memoization)
        
        if(coins[i] > amount)
            return t[i][amount] = solve(i+1, coins, amount);  
            // ⚡ Optimization: If current coin is bigger than amount → skip this coin
        
        int take = solve(i, coins, amount - coins[i]);  
        // Case 1: Take the coin → stay at i (unlimited coins allowed), reduce amount
        
        int skip = solve(i+1, coins, amount);  
        // Case 2: Skip the coin → move to next coin, same amount
        
        return t[i][amount] = take + skip;  
        // ✅ Total ways = ways by taking + ways by skipping
    }
    
    int change(int amount, vector<int>& coins) {
        n = coins.size();  
        // Number of available coin types

        memset(t, -1, sizeof(t));  
        // Initialize DP table with -1 (uncomputed states)

        return solve(0, coins, amount);  
        // Start recursion from coin index 0 and target = amount
    }
};
