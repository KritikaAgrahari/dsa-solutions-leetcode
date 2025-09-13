class Solution {
public:
    // Directions: Down, Up, Right, Left - used to move to adjacent cells in the grid
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Depth-First Search function to explore all land cells ('1') connected to (i, j)
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Boundary and base condition: If the cell is out of bounds or not land, return
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;

        // Optional: This lambda can be used to cleanly check if a move is valid
        /*
        auto isSafe = [&](int &i, int &j) {
            if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
                return false;
            return true;
        };
        */

        // Mark the current land cell as visited by changing it to a placeholder (e.g., '$')
        grid[i][j] = '$';

        // Explore all 4 directions (up, down, left, right)
        for(pair<int, int> &p : dir) {
            int i_ = i + p.first;   // New row index
            int j_ = j + p.second;  // New column index
            dfs(grid, i_, j_);      // Recursive DFS call on the neighbor
        }
    }

    // Main function to count the number of islands
    int numIslands(vector<vector<char>>& grid) {
        // Edge case: if the grid is empty, return 0
        if(grid.size() == 0)
            return 0;

        int m = grid.size();      // Total number of rows
        int n = grid[0].size();   // Total number of columns
        int count = 0;            // To store the number of islands

        // Loop through each cell in the grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If the current cell is land ('1'), start DFS from there
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);  // Visit and mark the entire island
                    count++;          // Increment the island count
                }
            }
        }

        return count; // Return the total number of islands found
    }
};
