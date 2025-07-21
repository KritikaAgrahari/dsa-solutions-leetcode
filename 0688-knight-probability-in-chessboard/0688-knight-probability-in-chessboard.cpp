class Solution {
public:
    // Hash map to memoize results: key -> probability
    unordered_map<string, double> mp;

    // All 8 possible moves for a knight in chess
    vector<pair<int, int>> directions = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, 
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
    };

    // Helper function to calculate probability recursively
    double helper(int N, int K, int row, int col) {
        // If knight moves out of board, return 0 probability
        if (row < 0 || row >= N || col < 0 || col >= N)
            return 0;

        // If no moves left, knight is still on the board, return 1
        if (K == 0)
            return 1;

        // Create a unique key for current state (K, row, col)
        string key = to_string(K) + "_" + to_string(row) + "_" + to_string(col);

        // If already computed, return memoized result
        if (mp.find(key) != mp.end())
            return mp[key];

        double ans = 0;  // Variable to accumulate total probability

        // Try all 8 possible knight moves
        for (int i = 0; i < directions.size(); i++) {
            int new_row = row + directions[i].first;   // Move to new row
            int new_col = col + directions[i].second;  // Move to new column

            // Recursively calculate probability from the new position
            ans += helper(N, K - 1, new_row, new_col);
        }

        // Store the average probability in the map and return it
        return mp[key] = ans / 8.0;
    }

    // Main function to calculate probability after k moves starting from (row, column)
    double knightProbability(int n, int k, int row, int column) {
        return helper(n, k, row, column);  // Call helper with initial values
    }
};
