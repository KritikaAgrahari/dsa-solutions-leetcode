class Solution {
public:

    void moveZeroes(vector<int>& nums) {
         int index = 0;  // Pointer to track the position of the next non-zero element
        
        // Move non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];  // Move non-zero element to the front
            }
        }
        
        // Fill remaining positions with zeros
        while (index < nums.size()) {
            nums[index++] = 0;
        }
    
    }
};