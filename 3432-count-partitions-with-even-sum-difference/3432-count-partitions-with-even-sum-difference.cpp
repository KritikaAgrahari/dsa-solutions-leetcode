class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long totalSum = 0;

        // Compute total sum of the array
        for (int x : nums) {
            totalSum += x;
        }

        /*
            Key Logic:
            The sum difference = leftSum - rightSum
            = leftSum - (totalSum - leftSum)
            = 2 * leftSum - totalSum

            For the difference to be EVEN:
            2 * leftSum - totalSum must be even.
            2 * leftSum is always even.

            → So totalSum must also be even.
            
            If totalSum is odd → NO partition can give even difference.
            If totalSum is even → ALL (n-1) partitions work.
        */

        if (totalSum % 2 != 0) {
            // Total sum is odd → No valid partitions
            return 0;
        }

        // Total sum is even → Every split index 0 to n-2 is valid
        return nums.size() - 1;
    }
};
