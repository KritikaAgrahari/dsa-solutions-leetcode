class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i = 0;               // pointer to previous non-equal value
        int count = 0;           // to count hills and valleys
        int n = nums.size();

        // Traverse the array starting from the second element
        for (int j = 1; j < n - 1; ++j) {
            // Skip if nums[j] is equal to nums[j+1] (flattened region)
            if (nums[j] == nums[j + 1]) continue;

            // Check if nums[j] is a hill or a valley
            if ((nums[i] < nums[j] && nums[j] > nums[j + 1]) ||  // hill
                (nums[i] > nums[j] && nums[j] < nums[j + 1])) {  // valley
                count++;
                i = j; // update i to current j (last distinct point)
            }
        }

        return count;
    }
};
