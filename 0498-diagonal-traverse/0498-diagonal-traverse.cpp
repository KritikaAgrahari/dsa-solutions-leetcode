class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();   // Number of rows in the matrix
        int n = mat[0].size(); // Number of columns in the matrix
        
        map<int, vector<int>> mp; // Map to group elements by diagonal (key = i+j, value = list of elements)
        
        vector<int> result; // Final result array to store diagonal traversal
        
        // Fill the map using i+j as the key (all elements on the same diagonal have same i+j)
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[i+j].push_back(mat[i][j]); // Insert element into its diagonal group
            }
        }
        
        bool flip = true; // Flag to alternate reversal of diagonals
        for(auto &it : mp) { // Iterate over diagonals in order of i+j
            if(flip) {
                // Reverse the diagonal elements to match required order
                reverse(it.second.begin(), it.second.end());
            }
            
            // Add all elements of this diagonal to result
            for(int &num : it.second) {
                result.push_back(num);
            }
            
            // Flip the flag to alternate direction for next diagonal
            flip = !flip;
        }
        
        return result; // Return final diagonal traversal
    }
};
