class Solution {
public://Wormhole Teleportation technique
    string reverseParentheses(string s) {
        int n = s.length(); // Length of the input string
        stack<int> openBracket; // Stack to store indices of '('
        vector<int> door(n); // 'door[i]' will store the matching index for bracket at position i

        // First pass: Match each pair of parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBracket.push(i); // Push index of opening bracket
            } else if (s[i] == ')') {
                int j = openBracket.top(); // Get the index of the matching '('
                openBracket.pop();         // Remove it from the stack
                door[i] = j; // Store mapping from ')' to '('
                door[j] = i; // Store mapping from '(' to ')'
            }
        }

        // Second pass: Traverse the string and simulate the reversal
        string result;       // This will store the final output
        int direction = 1;   // Initial direction: left to right
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                // If we hit a bracket, jump to its matching pair
                i = door[i];
                // Reverse the direction of traversal (simulate string reversal)
                direction = -direction;
            } else {
                // If it's a regular character, add it to the result
                result += s[i];
            }
        }

        // Return the final reversed and cleaned string
        return result;
    }
};
