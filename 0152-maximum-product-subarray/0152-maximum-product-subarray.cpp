class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int maxi = nums[0];  // Stores maximum product ending at current index
        int mini = nums[0];  // Stores minimum product ending at current index
        int ans = nums[0];   // Stores overall maximum product

        for(int i = 1; i < n; i++) {

            if(nums[i] < 0) {
                swap(maxi, mini);  // Negative number reverses maximum and minimum
            }

            maxi = max(nums[i], maxi * nums[i]);  // Choose current element alone or extend previous maximum
            mini = min(nums[i], mini * nums[i]);  // Choose current element alone or extend previous minimum

            ans = max(ans, maxi);  // Update overall maximum product
        }

        return ans;  // Return maximum product found
    }
};