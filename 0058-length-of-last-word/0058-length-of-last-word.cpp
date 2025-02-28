class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0, i = s.length() - 1;
        
        // Ignore trailing spaces (if any)
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};
