class Solution {
public:
    string decodeString(string s) {

        stack<int> numberStack;      // Stores repeat numbers
        stack<char> stringStack;     // Stores characters

        int num = 0;

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {     // If digit, build the complete number
                num = num * 10 + (s[i] - '0');
            }

            else if (s[i] == '[') {  // Save number and '['
                numberStack.push(num);
                stringStack.push('[');
                num = 0;
            }

            else if (isalpha(s[i])) { // Push letters
                stringStack.push(s[i]);
            }

            else if (s[i] == ']') {   // Decode when ']' is found

                string temp = "";

                // Pop until '['
                while (stringStack.top() != '[') {
                    temp = stringStack.top() + temp;
                    stringStack.pop();
                }

                stringStack.pop();      // Remove '['

                int repeat = numberStack.top();
                numberStack.pop();

                string repeated = "";

                for (int j = 0; j < repeat; j++) {
                    repeated += temp;
                }

                // Push repeated string back character by character
                for (int j = 0; j < repeated.size(); j++) {
                    stringStack.push(repeated[j]);
                }
            }
        }

        // Build final answer
        string ans = "";

        while (!stringStack.empty()) {
            ans = stringStack.top() + ans;
            stringStack.pop();
        }

        return ans;
    }
};