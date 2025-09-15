class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Store all broken letters in a set for O(1) lookup
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        
        int count = 0;   // Count of words that can be typed
        bool canType = true;  // Flag to check if current word can be typed
        
        // Traverse the text character by character
        for (int i = 0; i < text.size(); i++) {
            char c = text[i];
            
            if (c == ' ') {
                // End of a word reached
                if (canType) count++;  // If no broken letters were found, count the word
                canType = true;        // Reset flag for the next word
            } 
            else if (broken.count(c)) {
                // If a broken letter is found in this word
                canType = false;
            }
        }
        
        // Handle the last word (since it won't end with a space)
        if (canType) count++;
        
        return count;
    }
};
