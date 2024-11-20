#include <vector>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex = 0;          // Index for placing positive numbers
        int negIndex = 1;          // Index for placing negative numbers
        int n = nums.size();       // Get the size of the array
        vector<int> result(n);     // Create a result array of the same size

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {     // If the current number is negative
                result[negIndex] = nums[i];  // Place the negative number
                negIndex += 2;      // Move to the next position for negatives
            } else {                // If the current number is positive
                result[posIndex] = nums[i];  // Place the positive number
                posIndex += 2;      // Move to the next position for positives
            }
        }

        return result;              // Return the rearranged array
    }
};
