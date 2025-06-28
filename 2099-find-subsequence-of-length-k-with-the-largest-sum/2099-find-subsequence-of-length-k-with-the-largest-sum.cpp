class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // If k is equal to the size of nums, return the entire array
        if (k == nums.size())
            return nums;

        // Create a temporary copy of nums to identify the k largest elements
        vector<int> temp(nums);

        // Rearrange temp such that the k largest elements are in the first k positions (unordered)
        // This is done using nth_element with a greater comparator (for descending order)
        // Average time complexity is O(n)
        nth_element(begin(temp), begin(temp) + k - 1, end(temp), greater<int>());

        // Identify the k-th largest element, which will serve as the threshold value
        int threshold = temp[k - 1];

        // Count how many times the threshold appears in the top k elements
        int countThreshold = count(temp.begin(), temp.begin() + k, threshold);

        // Vector to store the result subsequence
        vector<int> result;

        // Traverse the original nums array to maintain original order
        for (int num : nums) {
            // If the number is greater than the threshold, it's part of the top k
            if (num > threshold) {
                result.push_back(num);
            }
            // If it's equal to the threshold and we still need to include such values
            else if (num == threshold && countThreshold > 0) {
                result.push_back(num);
                --countThreshold;  // Decrease the count of threshold values to include
            }

            // Stop if we have collected k elements
            if (result.size() == k)
                break;
        }

        // Return the subsequence of length k with the largest sum (preserving order)
        return result;
    }
};
