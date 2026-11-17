
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();  // Number of coin denominations

        // Create a 2D DP table with n+1 rows and amount+1 columns
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));

        // Base case: To make amount 0, we need 0 coins
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Traverse each coin
        for (int i = 1; i <= n; i++) {

            // Check every amount from 1 to the target amount
            for (int j = 1; j <= amount; j++) {

                // If current coin is greater than the amount, we cannot take it
                if (coins[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                }

                // Otherwise, choose the minimum between two possibilities
                else {
                    // Option 1: Do not take the current coin
                    // Option 2: Take the current coin (add 1) and solve remaining amount
                    dp[i][j] = min(dp[i - 1][j],
                                   1 + dp[i][j - coins[i - 1]]);
                }
            }
        }

        // If the answer is greater than amount, no valid combination exists
        if (dp[n][amount] > amount) {
            return -1;
        }

        // Return the minimum number of coins
        return dp[n][amount];
    }
};
