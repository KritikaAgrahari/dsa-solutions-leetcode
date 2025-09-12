class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels = 0;  
        // counter to store number of vowels

        // traditional for loop to iterate over each character in the string
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];  // get the character at index i
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;  // increment counter if character is a vowel
            }
        }

        // if there is at least one vowel, Alice wins
        return vowels > 0;
    }
};
