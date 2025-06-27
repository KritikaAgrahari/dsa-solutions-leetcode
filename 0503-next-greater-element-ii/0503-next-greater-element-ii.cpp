class Solution {
public:
    // Function to find the next greater element in a circular array
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array

        vector<int> result(n, -1); // Initialize result array with -1s (default if no next greater exists)

        stack<int> st; // Stack to store indices of elements for which next greater element is not yet found

        // Traverse the array twice to handle the circular condition
        for (int i = 0; i < 2 * n; i++) {
            int curr = nums[i % n]; // Use modulo to wrap around the array circularly

            // If stack is not empty and current element is greater than the element at top index of stack
            while (!st.empty() && nums[st.top()] < curr) {
                result[st.top()] = curr; // Assign current element as the next greater for index on top of stack
                st.pop(); // Remove that index from stack as we have found its next greater
            }

            // Push index to stack only in the first pass (i < n)
            if (i < n) st.push(i);
        }

        return result; // Return the final result containing next greater elements
    }
};
