class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();       // Number of rows
        int n = grid[0].size();    // Number of columns

        vector<int> arr;

        // Step 1: Convert the 2D grid into a 1D array
        // This makes it easier to perform rotation using reverse().
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        // Step 2: Calculate the total number of elements
        int total = m * n;

        // If k is greater than or equal to total, remove unnecessary rotations
        k = k % total;

        // Step 3: Reverse the entire array
        // This puts the last k elements at the beginning in reversed order.
        reverse(arr.begin(), arr.end());

        // Step 4: Reverse the first k elements
        // This restores the original order of the last k elements.
        reverse(arr.begin(), arr.begin() + k);

        // Step 5: Reverse the remaining elements
        // This restores the original order of the remaining elements.
        reverse(arr.begin() + k, arr.end());

        // Step 6: Create a new 2D grid to store the rotated elements
        vector<vector<int>> ans(m, vector<int>(n));

        int index = 0;

        // Step 7: Convert the rotated 1D array back into a 2D grid
        // Fill each row and column sequentially.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = arr[index++];
            }
        }

        // Step 8: Return the shifted 2D grid
        return ans;
    }
};