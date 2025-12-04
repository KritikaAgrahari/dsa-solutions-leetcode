class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        // Shifting by n is pointless, so reduce k
        k %= n;

        for (int i = 0; i < m; i++) {

            vector<int> shifted(n);  // will store the shifted version of row i

            if (i % 2 == 0) {
                // EVEN-index row → shift LEFT by k
                for (int j = 0; j < n; j++) {
                    shifted[j] = mat[i][(j + k) % n];
                }
            } else {
                // ODD-index row → shift RIGHT by k
                // right shift is same as (j - k + n) % n
                for (int j = 0; j < n; j++) {
                    shifted[j] = mat[i][(j - k + n) % n];
                }
            }

            // If shifted row does not match the original row, return false
            if (shifted != mat[i]) return false;
        }

        // If all rows match after shifts, matrix is unchanged
        return true;
    }
};
