class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        for (int i = 0; i < nums.size(); i++) {
            int r = nums[i] % 3;

            if (r == 0) {
                // already divisible by 3
                continue;
            }

            // either subtract r OR add (3 - r)
            int add = 3 - r;

            if (r <= add) {
                operations += r;
            } else {
                operations += add;
            }
        }

        return operations;
    }
};
