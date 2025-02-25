class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
         vector<int> result(2 * n);
    for (int i = 0; i < n; i++) {
        result[2 * i] = nums[i];      // Place x1, x2, ..., xn at even indices
        result[2 * i + 1] = nums[i + n];  // Place y1, y2, ..., yn at odd indices
    }
    return result;
        
    }
};