class Solution {
public:
    int l, m, n; // l = length of word, m = number of rows, n = number of columns
    
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // Recursive DFS function to check if the word can be found starting from (i, j)
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        // Base case: if all characters have been matched
        if(idx >= l)
            return true;

        // Boundary check and character mismatch check
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;

        // Store current character and mark cell as visited
        char temp = board[i][j];
        board[i][j] = '$'; // Use '$' as a marker for visited cell

        // Explore all four directions
        for(auto& dir : directions) {
            int i_ = i + dir[0]; // Next row
            int j_ = j + dir[1]; // Next column
            
            // Recursively search from the next cell
            if(find(board, i_, j_, word, idx + 1))
                return true; // If found in any direction, return true
        }

        // Backtrack: restore the original character
        board[i][j] = temp;
        return false; 
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); // Total rows
        n = board[0].size(); // Total columns
        l = word.length(); // Length of the word to find

        // Early pruning: if total cells are less than the length of the word
        if(m * n < l)
            return false;

        // Try starting from each cell that matches the first character of the word
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true; 
                }
            }
        }

        return false; 
    }
};
