

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0, bitmask = 0, left = 0;

        for (int right = 0; right < n; right++) {
            // Shrink the window until it's "nice"
            while ((bitmask & nums[right]) != 0) {
                bitmask ^= nums[left];  // Remove leftmost element
                left++;
            }
            // Expand the window
            bitmask |= nums[right];
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
