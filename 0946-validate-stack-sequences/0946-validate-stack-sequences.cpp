class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; 

        int n = pushed.size(); 

        int i = 0, j = 0;
        while (i < n && j < n) {

            st.push(pushed[i]); 
            while (!st.empty() && j < n && st.top() == popped[j]) {
                st.pop(); // Pop from stack as it matches 'popped[j]'
                j++;      
            }

            i++; 
        }

        return st.empty();
    }
};
