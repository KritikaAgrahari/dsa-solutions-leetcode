class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();             // Get the length of input string
    int start = 0, maxLen = 1;      // Initialize:
                                    // 'start' = starting index of longest palindrome found
                                    // 'maxLen' = length of longest palindrome (at least 1)

    // Loop through each character in the string
    for (int i = 0; i < n; i++) {

        // Inner loop runs two times to handle both:
        // j = 0 -> odd-length palindrome centered at i
        // j = 1 -> even-length palindrome centered between i and i+1
        for (int j = 0; j <= 1; j++) {
            int low = i;            // Left pointer starting at center
            int high = i + j;       // Right pointer starting at center (or one ahead for even-length)

            // Expand substring while:
            // 1. low is within bounds (>= 0)
            // 2. high is within bounds (< n)
            // 3. characters at low and high are equal
            while (low >= 0 && high < n && s[low] == s[high]) 
            {
                int currLen = high - low + 1; // Current palindrome length

                // If this palindrome is longer than previously found max
                if (currLen > maxLen) {
                    start = low;    // Update starting index of longest palindrome
                    maxLen = currLen; // Update maximum length
                }

                // Expand outward to check larger substring
                low--;   // Move left pointer one step left
                high++;  // Move right pointer one step right
            }
            // When while loop ends:
            // - either characters don't match OR
            // - low/high went out of string bounds
            // So current expansion cannot grow further
        }
        // After both j=0 and j=1, we have checked all palindromes centered at i
    }

    // Return the longest palindrome substring found
    return s.substr(start, maxLen);
    }
};