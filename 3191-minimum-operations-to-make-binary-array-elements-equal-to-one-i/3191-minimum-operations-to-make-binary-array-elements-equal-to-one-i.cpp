class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        
        for (int i = 0; i <= n - 3; ) {
            if (nums[i] == 0) {
                // Flip the triplet starting at index i
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
            i++; // Move to the next element
        }
        
        // If there are still zeros in the last two positions, it's impossible
        return (nums[n - 1] == 0 || nums[n - 2] == 0) ? -1 : operations;
    }
};
