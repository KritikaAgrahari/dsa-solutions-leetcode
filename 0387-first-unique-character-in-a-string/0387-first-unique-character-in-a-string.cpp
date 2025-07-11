class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0); // Frequency array for lowercase letters

        // First pass: Count frequency of each character
        for (int i = 0; i < s.length(); ++i) {
            freq[s[i] - 'a']++;
        }

        // Second pass: Find the first character with frequency 1
        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1; // No unique character found
    }
};
