class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // Maps element to its next greater
        stack<int> st; // Stack to keep track of decreasing elements

        // Process nums2 to fill the map
        for (int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];

            // Pop smaller elements from stack and assign current number as their next greater
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }

            // Push current element
            st.push(num);
        }

        // For remaining elements in stack, no next greater exists
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Build result for nums1 using the map
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(nextGreater[nums1[i]]);
        }

        return ans;
    }
};
