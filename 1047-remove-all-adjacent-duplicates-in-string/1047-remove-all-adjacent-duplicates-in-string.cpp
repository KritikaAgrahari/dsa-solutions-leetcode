class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n =s.length();
        for (int i=0; i<n ; i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();  // Remove duplicate
            } else {
                st.push(s[i]);
            }
        }
        
        // Build result from stack
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());  // Stack stores in reverse order
        
        return result;
    }
};
