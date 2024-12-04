class Solution {
public:

    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0;
        
        // Traverse both strings
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                j++;  // Match found, move pointer in t
            }
            i++;  // Always move pointer in s
        }
        
        // Characters left to append from t
        return m - j;
    }
};
