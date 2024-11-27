class Solution {
public:

    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // Initialize a row with all 1s
        
        // Compute values based on previous row's values
        for (int i = 1; i <= rowIndex; ++i) {
            // Start from the end to avoid overwriting values we still need
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    
        
    }
};
