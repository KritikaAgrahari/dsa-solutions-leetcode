// class Solution {
// public:
//     // Function to check whether a character is a vowel
//     bool isVowel(char ch) {
//         ch = tolower(ch); // Convert character to lowercase to handle both cases
//         return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); 
//         // Return true if character is a vowel, else false
//     }

//     // Function to sort only vowels in a string while keeping consonants in place
//     string sortVowels(string s) {
//         string temp; // Temporary string to store all vowels

//         // Traverse through the input string
//         for (int i = 0; i < s.length(); i++) {
//             char ch = s[i]; // Get current character
//             if (isVowel(ch)) { 
//                 temp.push_back(ch); // If it's a vowel, store it in temp
//             }
//         }

//         // Sort the vowels collected in temp
//         sort(temp.begin(), temp.end());

//         int j = 0; // Index for temp (sorted vowels)

//         // Traverse the input string again
//         for (int i = 0; i < s.length(); i++) {
//             if (isVowel(s[i])) { 
//                 s[i] = temp[j]; // Replace vowel with sorted vowel
//                 j++; // Move to next vowel in temp
//             }
//         }

//         return s; // Return the modified string
//     }
// };


class Solution {
public:
    // Function to check whether a character is a vowel
    bool isVowel(char ch) {
        ch = tolower(ch); // Convert character to lowercase for uniformity
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); 
        // Return true if the character is a vowel, else false
    }

    // Function to sort vowels in the string while keeping consonants fixed
    string sortVowels(string s) {
        unordered_map<char, int> mp; // Map to store frequency of each vowel

        // Step 1: Count frequencies of vowels in the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i]; // Get current character
            if (isVowel(ch)) {
                mp[ch]++; // Increment frequency of this vowel
            }
        }

        // Ordered string of vowels (uppercase first, then lowercase)
        string temp = "AEIOUaeiou";

        int j = 0; // Pointer to track which vowel from 'temp' we are using

        // Step 2: Traverse the string again and replace vowels in sorted order
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                // Move 'j' forward until we find a vowel with non-zero frequency
                while (mp[temp[j]] == 0) {
                    j++;
                }

                s[i] = temp[j];    // Replace current vowel with sorted vowel
                mp[temp[j]]--;     // Decrease frequency count of that vowel
            }
        }

        return s; // Return the updated string
    }
};
