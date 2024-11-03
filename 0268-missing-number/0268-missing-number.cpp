class Solution {

public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Calculate the sum of the first n natural numbers
        int sum_n = n * (n + 1) / 2;
        
        // Calculate the sum of the numbers in nums
        int sum_nums = 0;
        for (int num : nums) {
            sum_nums += num;
        }
        
        // The missing number is the difference between sum_n and sum_nums
        return sum_n - sum_nums;
    }
};
