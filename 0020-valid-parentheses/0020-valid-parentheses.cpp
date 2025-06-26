class Solution {
public:
    bool isValid(string s) {
         stack<char> st;  // Stack to store opening brackets

    // Traditional for loop to go through each character of the string
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If current character is an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // If it's a closing bracket
        else {
            // If stack is empty, there's no matching opening bracket
            if (st.empty()) {
                return false;
            }

            // Check the top of the stack
            char top = st.top();

            // If the current closing bracket matches the top of the stack
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();  // Pop the matched opening bracket
            } else {
                return false;  // Mismatch found
            }
        }
    }

    // At the end, stack should be empty if all brackets matched
    return st.empty();
    }
};