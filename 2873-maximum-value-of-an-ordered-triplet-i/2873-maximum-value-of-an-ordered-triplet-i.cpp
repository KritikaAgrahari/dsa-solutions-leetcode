class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_left(n, 0), max_right(n, 0);
        
        // Compute prefix max (max_left)
        int left_max = 0;
        for (int i = 1; i < n; i++) {
            left_max = max(left_max, nums[i - 1]);
            max_left[i] = left_max;
        }

        // Compute suffix max (max_right)
        int right_max = 0;
        for (int i = n - 2; i >= 0; i--) {
            right_max = max(right_max, nums[i + 1]);
            max_right[i] = right_max;
        }

        // Compute maximum triplet value
        long long max_value = 0;
        for (int j = 1; j < n - 1; j++) {
            long long val = (long long)(max_left[j] - nums[j]) * max_right[j];
            max_value = max(max_value, val);
        }

        return max_value;
    }
};
