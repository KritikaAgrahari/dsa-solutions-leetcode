class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        // Square each element in-place
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        // Sort the squared values
        sort(nums.begin(), nums.end());

        return nums; // Return the sorted squared array
    }
};
