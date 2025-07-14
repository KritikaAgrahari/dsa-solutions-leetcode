class Solution {
public:
    // Function to find the length of the longest substring where we can replace at most k characters to make all letters the same
    int characterReplacement(string s, int k) {
        int maxLength = 0;         // Stores the length of the longest valid substring
        int maxCharCount = 0;      // Keeps track of the most frequent character count in the current window
        int start = 0;             // Left boundary of the sliding window

        vector<int> freq(26, 0);   // Array to count frequency of each letter (A-Z) in the window

        // Loop through each character with 'end' as the right boundary of the window
        for (int end = 0; end < s.length(); end++) {
            freq[s[end] - 'A']++;                     // Increase the count of current character
            maxCharCount = max(maxCharCount, freq[s[end] - 'A']); // Update the max frequency in the window

            // If characters to replace > k, shrink the window from the left
            if ((end - start + 1) - maxCharCount > k) {
                freq[s[start] - 'A']--;               // Decrease the frequency of the character going out of the window
                start++;                              // Move left pointer forward to shrink the window
            }

            // Update the result if the current window is larger
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;  // Return the maximum length found
    }
};
