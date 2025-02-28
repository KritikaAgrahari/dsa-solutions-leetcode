class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        
        // XOR all characters of s
        for (int i = 0; i < s.length(); i++) {
            result ^= s[i];
        }

        // XOR all characters of t
        for (int i = 0; i < t.length(); i++) {
            result ^= t[i];
        }

        return result;
    }
};
