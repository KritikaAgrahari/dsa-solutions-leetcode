class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {  // Loop till n-1 to avoid out-of-bounds
            if ((nums[i] % 2 == nums[i + 1] % 2))  // Check if adjacent numbers are both even or both odd
                return false;
        }
        
        return true;  // If no adjacent numbers are the same type (odd/even), return true
    }
};
