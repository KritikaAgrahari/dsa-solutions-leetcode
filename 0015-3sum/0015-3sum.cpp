
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if(nums.size() < 3)                 // Check minimum size
            return {};

        vector<vector<int>> result;         // Store triplets

        sort(nums.begin(), nums.end());     // Sort the array

        for(int i = 0; i < nums.size() - 2; i++) { // Fix first element

            if(i != 0 && nums[i] == nums[i-1]) {   // Skip duplicates
                continue;
            }

            int j = i + 1;                  // Second pointer
            int k = nums.size() - 1;         // Third pointer

            int target = -nums[i];          // Required target sum

            while(j < k) {                  // Two pointer approach

                if(nums[j] + nums[k] > target)
                    k--;                    // Decrease sum

                else if(nums[j] + nums[k] < target)
                    j++;                    // Increase sum

                else {
                    result.push_back({-target, nums[j], nums[k]}); // Store triplet

                    while(j < k && nums[j] == nums[j+1])
                        j++;                // Skip duplicate elements

                    while(j < k && nums[k] == nums[k-1])
                        k--;                // Skip duplicate elements

                    j++;                    // Move left pointer
                    k--;                    // Move right pointer
                }
            }
        }

        return result;                      // Return result
    }
};
