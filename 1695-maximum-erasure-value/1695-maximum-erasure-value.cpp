class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // This set keeps track of elements in our current subarray
        unordered_set<int> seen;

        int left = 0; // Left pointer of the window
        int right = 0; // Right pointer of the window

        int currentSum = 0; // Sum of current window/subarray
        int maxScore = 0;   // Store the maximum sum found

        // Loop through the array using right pointer
        while (right < nums.size()) {

            // If nums[right] is already in the set → it means duplicate!
            while (seen.count(nums[right])) {
                // Remove the leftmost element from window
                seen.erase(nums[left]);      // Remove it from the set
                currentSum -= nums[left];    // Subtract its value from current sum
                left++;                      // Move the left pointer forward
            }

            // Now nums[right] is unique in window → add it
            seen.insert(nums[right]);         // Add element to the set
            currentSum += nums[right];        // Add value to current sum

            // Update the max score if this sum is greater
            maxScore = max(maxScore, currentSum);

            // Move the right pointer to include next number
            right++;
        }

        // Return the best sum found
        return maxScore;
    }
};
