class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Initialize a vector to track if a positive number has been added to the sum
        // Since values range from 1 to 100, we use size 101 for 1-based indexing
        vector<int> st(101, -1); 

        // Variable to store the total sum of unique positive numbers
        int sum = 0;

        // Variable to keep track of the maximum negative number encountered
        int maxNeg = INT_MIN;

        // Traditional for loop to iterate through each number in the input array
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];  // Current number from the array

            if(num <= 0) {
                // If the number is zero or negative, update maxNeg if it's larger
                maxNeg = max(maxNeg, num);
            } else if(st[num] == -1) {
                // If the number is positive and hasn't been added before
                sum += num;      // Add it to the sum
                st[num] = 1;     // Mark this number as added
            }
        }

        // If no positive numbers were added (sum is still 0), return the maximum negative number
        // Otherwise, return the computed sum of unique positive numbers
        return sum == 0 ? maxNeg : sum;
    }
};
