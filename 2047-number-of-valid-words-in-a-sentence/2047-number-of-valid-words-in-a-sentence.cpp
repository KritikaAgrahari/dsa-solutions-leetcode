
class Solution {
public:
    int countValidWords(string sentence) {
        int count = 0;           // Stores number of valid words
        string word = "";        // Stores one word at a time

        for (int i = 0; i <= sentence.size(); i++) {

            // Check if space or end of sentence is reached
            if (i == sentence.size() || sentence[i] == ' ') {

                if (word.empty()) continue;  // Skip extra spaces

                bool valid = true;           // Assume word is valid
                int hyphen = 0, punct = 0;   // Count hyphens and punctuation

                // Check each character of the word
                for (int j = 0; j < word.size(); j++) {
                    char ch = word[j];

                    if (isdigit(ch)) {       // Digits are not allowed
                        valid = false;
                    }

                    else if (ch == '-') {    // Check hyphen
                        hyphen++;

                        // Hyphen must be single and between letters
                        if (hyphen > 1 || j == 0 || j == word.size()-1 ||
                            !islower(word[j-1]) || !islower(word[j+1]))
                            valid = false;
                    }

                    else if (ch == '!' || ch == '.' || ch == ',') {
                        punct++;             // Count punctuation

                        // Punctuation must appear only once at the end
                        if (punct > 1 || j != word.size()-1)
                            valid = false;
                    }
                }

                if (valid) count++;  // Increase count if word is valid

                word = "";           // Clear word for next token
            }
            else {
                word += sentence[i]; // Add character to current word
            }
        }

        return count;                // Return total valid words
    }
};
