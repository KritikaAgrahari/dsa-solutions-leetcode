class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(); 

        int maxSum = 0;      
        int sum = nums[0];   

        for (int i = 1; i < n; i++) {\
            if (nums[i] > nums[i - 1]) { 
                sum += nums[i]; 
            } else {
                // If the ascending order breaks
                maxSum = max(maxSum, sum); // Update maxSum if current sum is greater
                sum = nums[i]; // Start a new sum from the current element
            }
        }

        return max(maxSum, sum); 
    }
};
