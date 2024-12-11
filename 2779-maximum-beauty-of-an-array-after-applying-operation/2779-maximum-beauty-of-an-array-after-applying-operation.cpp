class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
              // Sort the array
        sort(nums.begin(), nums.end());
        
        int maxBeauty = 0; // To store the maximum beauty
        int i = 0; // Left pointer
        
        // Sliding window
        for (int j = 0; j < nums.size(); j++) {
            // Check if the current range is valid
            while (nums[j] - nums[i] > 2 * k) {
                i++; // Shrink the window
            }
            // Update the maximum beauty (length of the valid window)
            maxBeauty = max(maxBeauty, j - i + 1);
        }
        
        return maxBeauty;
    
        
    }
};