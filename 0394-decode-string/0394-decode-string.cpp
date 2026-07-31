class Solution {
public:

    int idx = 0;   // Global index to keep track of the current position in the string

    string helper(string &s) {   // Recursive function to decode the string

        string ans = "";         // Stores the decoded string of the current bracket
        int num = 0;             // Stores the repeat number before '['

        while (idx < s.size()) { // Traverse the string until the end

            if (isalpha(s[idx])) {      // If current character is a letter
                ans += s[idx];          // Add the letter directly to the answer
            }

            else if (isdigit(s[idx])) { // If current character is a digit
                num = num * 10 + (s[idx] - '0'); // Build the complete number (handles 12, 123, etc.)
            }

            else if (s[idx] == '[') {   // Found an opening bracket

                idx++;                  // Move to the first character inside '['

                string temp = helper(s); // Recursively decode everything inside the brackets

                for (int i = 0; i < num; i++) { // Repeat the decoded string 'num' times
                    ans += temp;
                }

                num = 0;                // Reset the repeat count for the next use
            }

            else if (s[idx] == ']') {   // Found the closing bracket
                return ans;             // Return the decoded string to the previous recursive call
            }

            idx++;                      // Move to the next character
        }

        return ans;                     // Return the final decoded string
    }

    string decodeString(string s) {     // Main function called by LeetCode
        return helper(s);               // Start decoding from index 0
    }
};