class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skip_s = 0, skip_t = 0;

        while (i >= 0 || j >= 0) {
            // Process backspaces in s
            while (i >= 0) {
                if (s[i] == '#') {
                    skip_s++;
                    i--;
                } else if (skip_s > 0) {
                    skip_s--;
                    i--;
                } else {
                    break;
                }
            }

            // Process backspaces in t
            while (j >= 0) {
                if (t[j] == '#') {
                    skip_t++;
                    j--;
                } else if (skip_t > 0) {
                    skip_t--;
                    j--;
                } else {
                    break;
                }
            }

            // Compare characters after backspace handling
            char first = (i >= 0) ? s[i] : '$';
            char second = (j >= 0) ? t[j] : '$';

            if (first != second) return false;

            // Move to the next character
            i--;
            j--;
        }

        return true;
    }
};
