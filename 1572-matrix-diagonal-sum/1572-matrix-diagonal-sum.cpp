
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int n = mat.size();  // Get matrix size
        int sum = 0;         // Initialize sum

        for (int i = 0; i < n; i++) {

            sum += mat[i][i];  // Add primary diagonal element

            sum += mat[i][n - i - 1];  // Add secondary diagonal element

            if (i == n - i - 1) {
                sum -= mat[i][i];  // Avoid counting middle element twice
            }
        }

        return sum;  // Return diagonal sum
    }
};
