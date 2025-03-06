class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        vector<int> count(N + 1, 0);
        int repeated, missing;
        
        // Count occurrences of each number
        for (auto& row : grid) {
            for (int num : row) {
                count[num]++;
            }
        }
        
        // Identify repeated and missing numbers
        for (int i = 1; i <= N; i++) {
            if (count[i] == 2) repeated = i;
            if (count[i] == 0) missing = i;
        }
        
        return {repeated, missing};
    }
};
