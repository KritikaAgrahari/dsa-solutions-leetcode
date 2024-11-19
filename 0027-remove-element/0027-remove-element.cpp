class Solution {

public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // `k` will count elements not equal to `val`
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move the element to the position `k`
                k++; // Increment the count of elements not equal to `val`
            }
        }
        
        return k;
    }
};
