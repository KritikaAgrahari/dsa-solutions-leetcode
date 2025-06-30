class Solution {
public:
    int maxDiff(int num) {
        // Convert the input number to a string for easy digit manipulation
        string str1 = to_string(num);  
        string str2 = str1;            // Copy of the original number as a string

        // Find the first digit in str1 that is not '9'
        int idx = str1.find_first_not_of('9');
        if(idx != string::npos) {
            char ch = str1[idx];  
            // Replace all occurrences of this digit with '9' to maximize the number
            replace(begin(str1), end(str1), ch, '9');
        }

        // Now work on minimizing the number (stored in str2)
        // Leading zeros are not allowed, so we handle index 0 differently

        for(int i = 0; i < str2.length(); i++) {
            char ch = str2[i];
            
            if(i == 0) {
                // For the first digit: replace it with '1' if it's not already '1'
                // because leading zeros are invalid in numbers
                if(ch != '1') {
                    replace(begin(str2), end(str2), ch, '1');
                    break;  // Only one digit can be chosen, so break after replacement
                }
            } 
            else if(ch != '0' && ch != str2[0]) {
                // For other digits (non-zero and not equal to the first digit):
                // Replace them with '0' to minimize the number
                // We avoid replacing a digit if it's same as str2[0] because
                // that would also change the first digit which we already handled
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }

        // Convert the modified strings back to integers and return the difference
        return stoi(str1) - stoi(str2);
    }
};
