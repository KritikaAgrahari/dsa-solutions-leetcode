class Solution {
public:
//     // The time complexity of the current solution is O(N)
//     bool isValid(string s) {
//         // Stack to keep track of opening brackets
//         stack<char> st;

//         // Iterate through the string characters using a traditional for loop
//         for (int i = 0; i < s.size(); i++) {
//             char c = s[i]; // Access the character at index i
            
//             // Push opening brackets onto the stack
//             if (c == '(' || c == '{' || c == '[') {
//                 st.push(c);
//             }
//             // For closing brackets, check if they match the top of the stack
//             else {
//                 // If the stack is empty, there's no matching opening bracket
//                 if (st.empty()) return false;

//                 char top = st.top();
//                 st.pop();

//                 // Check if the closing bracket matches the corresponding opening bracket
//                 if ((c == ')' && top != '(') ||
//                     (c == '}' && top != '{') ||
//                     (c == ']' && top != '[')) {
//                     return false;
//                 }
//             }
//         }

//         // If the stack is empty at the end, all brackets matched correctly
//         return st.empty();
//     }
// };
bool isValid(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(')
            balance++;
        else if (c == ')') {
            balance--;
            if (balance < 0) return false; // Closing bracket without matching opening bracket
        }
    }
    return balance == 0; // Ensure all opening brackets are matched
}
};
