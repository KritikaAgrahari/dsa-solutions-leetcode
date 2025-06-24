// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int count = 0;
//         for(int r=0 ; r<n ; r++){
//             for(int c=0; c<n; c++){
//                int isequal = true;
//                for(int i=0 ; i<n; i++){
//                 if(grid[r][i]!=grid[i][c]){
//                     isequal = false;
//                     break;

//                 }
//                }

//               count = count+isequal;
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();  // Get the number of rows (and columns, since it's a square grid)

        int count = 0;        // Initialize a counter for matching row-column pairs

        map<vector<int>, int> mp;  // Map to store frequency of each row (vector of ints)

        // Step 1: Store the frequency of each row in the map
        for (int row = 0; row < n; row++) {
            mp[grid[row]]++;  // Increment the count for this specific row vector
        }

        // Step 2: For each column, construct a column vector and check if it matches any row
        for (int c = 0; c < n; c++) {
            vector<int> temp;  // Temporary vector to build the current column

            for (int r = 0; r < n; r++) {
                temp.push_back(grid[r][c]);  // Extract element from each row to form the column
            }

            count += mp[temp];  // Add to count if this column vector matches any row vector(s)
        }

        return count;  // Return the number of equal row-column pairs
    }
};
