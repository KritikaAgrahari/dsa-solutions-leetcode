class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp; // Map to store next greater element for each number in nums2
        stack<int> st; // Stack to help find next greater elements

        // Traverse nums2 using traditional for loop
        for (int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];

            // While stack is not empty and current number is greater than top of stack
            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num; // Set current number as next greater
                st.pop(); // Remove the top element
            }

            st.push(num); // Push current number to stack
        }

        // For remaining elements, no next greater element exists
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Prepare result for nums1 using the map
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};
