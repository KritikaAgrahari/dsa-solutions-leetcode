class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(); // Get the length of the string
        
        // Loop through the string character by character
        for (int i = 0; i < n; i++) {
            
            if (s[i] != ' ') {
                
                int j = i; // Set j to the start of the word
                
                while (j < n && s[j] != ' ') {
                    j++;
                }
                
                reverse(s.begin() + i, s.begin() + j);
                
                i = j;
            }
        }
        
        return s;
    }
};
