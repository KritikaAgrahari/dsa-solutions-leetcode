class Solution {
public:
    vector<vector<int>> result;  

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        if(idx >= nums.size()) {
            result.push_back(temp);  
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);  
        temp.pop_back();
        solve(nums, idx + 1, temp);  
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;  // Temporary vector to hold the current subset

        solve(nums, 0, temp);  // Start recursion from index 0

        return result;  
    }
};
