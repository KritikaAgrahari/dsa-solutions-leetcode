// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();

//         // Square each element in-place
//         for (int i = 0; i < n; i++) {
//             nums[i] = nums[i] * nums[i];
//         }

//         // Sort the squared values
//         sort(nums.begin(), nums.end());

//         return nums; // Return the sorted squared array
//     }
// };


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n); // Correctly initialize result array
        int i = 0, j = n - 1, k = n - 1;

        while (k >= 0) { // Loop must run until k >= 0
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];

            if (a > b) {
                result[k] = a;
                i++;  // Move left pointer forward
            } else {
                result[k] = b;
                j--;  // Move right pointer backward
            }
            k--; // Move position in result array
        }

        return result;
    }
};
