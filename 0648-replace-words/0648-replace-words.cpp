class Solution {
public:

    // Helper function to find the shortest root of a given word from the dictionary set
    string findRoot(string& word, unordered_set<string>& st) {
        
        // Try all prefixes of the word starting from length 1 to the full word
        for(int l = 1; l <= word.length(); l++) {
            string root = word.substr(0, l); // Get prefix of length 'l'

            if(st.count(root)) {  // Check if this prefix exists in the dictionary set
                return root;     // If yes, return it as the root
            }
        }

        return word;  // If no root is found, return the original word
    }

    // Main function to replace words in the sentence using dictionary roots
    string replaceWords(vector<string>& dictionary, string sentence) {

        // Create an unordered set for fast lookup of root words
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);  // Create a string stream to break sentence into words
        string word;                // Temporary variable to hold each word
        string result;             // Final result string

        // Read each word separated by spaces
        while(getline(ss, word, ' ')) {
            result += findRoot(word, st) + " ";  // Replace word with its root and append space
        }

        result.pop_back();  // Remove the trailing space at the end
        return result;      // Return the final modified sentence
    }
};
