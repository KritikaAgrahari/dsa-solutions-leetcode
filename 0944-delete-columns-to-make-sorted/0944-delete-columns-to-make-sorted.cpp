class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();    // Number of rows
        int m = strs[0].size(); // Number of columns
        int count = 0;          // To count unsorted columns
        
        // Iterate over each column (j represents columns)
        for (int i = 0; i < m; i++) {
            // Iterate over each row from the second row onwards (i represents rows)
        for (int j = 0; j < n-1; j++) {
                if (strs[j][i] > strs[j+1][i]) { // Check if column is unsorted
                    count++;   // Increment count if column is not sorted
                    break;    // No need to check further rows for this column
                }
            }
        }
        
        return count;
    }
};
