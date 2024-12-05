class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
         bool increasing = true, decreasing = true;  // Flags to check if the array is increasing or decreasing
        int n = nums.size();  // Get the size of the array

        
        // Traverse the array from index 1 (the second element) to the end
        for (int i = 1; i < n; ++i) {
            
            if (nums[i] > nums[i - 1]) {
                decreasing = false; // If we find an increasing pair, it can't be decreasing
            }
            if (nums[i] < nums[i - 1]) {
                increasing = false; // If we find a decreasing pair, it can't be increasing
            }

            // If both flags are false, it means the array is neither increasing nor decreasing
            if (!increasing && !decreasing) {
                return false; // No point in checking further, the array is not monotonic
            }
        }

        // If the loop finishes, that means the array is either increasing or decreasing (monotonic)
        return true;
    
    }
};
