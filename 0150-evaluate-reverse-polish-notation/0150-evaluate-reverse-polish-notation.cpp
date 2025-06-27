class Solution {
public:

    // Function to perform arithmetic operation based on operator string `s`
    int operate(int &a, int &b, const string &s) {
        if (s == "+") return b + a;   // If operator is '+', return b + a
        if (s == "-") return b - a;   // If operator is '-', return b - a
        if (s == "*") return b * a;   // If operator is '*', return b * a
        if (s == "/") return b / a;   // If operator is '/', return b / a
        return -1; // Return -1 if operator is not recognized (should not happen in valid input)
    }

    // Function to evaluate Reverse Polish Notation expression
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // Stack to store operands during evaluation

        // Loop through each token in the input
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i]; // Get the current token

            // If the token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = st.top(); st.pop(); // Pop top element (right-hand side operand)
                int b = st.top(); st.pop(); // Pop next element (left-hand side operand)

                int result = operate(a, b, token); // Perform the operation using helper function
                st.push(result); // Push the result back onto the stack
            } else {
                st.push(stoi(token)); // If token is a number, convert to int and push to stack
            }
        }

        return st.top(); // Final result is on top of the stack
    }
};
