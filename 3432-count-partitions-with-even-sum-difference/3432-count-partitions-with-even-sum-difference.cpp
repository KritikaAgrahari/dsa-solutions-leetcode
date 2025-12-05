class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long totalSum = 0;

        // Traditional for loop to compute the total sum
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        /*
            Explanation:
            difference = leftSum - rightSum
                       = 2 * leftSum - totalSum

            For difference to be EVEN:
            → totalSum must be EVEN.
            Because 2 * leftSum is always even.
        */

        // If total sum is odd → no valid partition exists
        if (totalSum % 2 != 0) {
            return 0;
        }

        // If totalSum is even → all (n-1) partitions are valid
        return nums.size() - 1;
    }
};
