class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();
        
        // Flatten grid into 1D vector
        for (auto& row : grid) {
            for (int num : row) {
                nums.push_back(num);
            }
        }

        // Check if transformation is possible
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[0]) % x != 0) {
                return -1; // Impossible case
            }
        }

        // Sort the array and find the median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        // Compute the minimum operations
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};
