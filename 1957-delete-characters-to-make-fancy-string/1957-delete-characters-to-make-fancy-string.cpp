class Solution {
public:
    string makeFancyString(string s) {
        string result;
        for (int i = 0; i < s.length(); ++i) {
            int n = result.size();
            // Check if last two characters in result are same as s[i]
            if (n >= 2 && result[n - 1] == s[i] && result[n - 2] == s[i]) {
                continue; // skip this character
            }
            result += s[i];
        }
        return result;
    }
};
