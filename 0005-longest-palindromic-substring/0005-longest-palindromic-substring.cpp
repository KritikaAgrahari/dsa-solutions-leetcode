// class Solution {
// public:
//     int t[1001][1001]; // DP table to store palindrome check results for substrings s[l..r]

//     // Function to check if substring s[l..r] is a palindrome
//     bool solve(string &s, int l, int r) {
//         if (l >= r) // Base case: single char or empty substring is always a palindrome
//             return 1;

//         if (t[l][r] != -1) { // If already computed, return stored result
//             return t[l][r];
//         }

//         if (s[l] == s[r]) {  
//             // If first and last characters match, check inside substring (l+1, r-1)
//             return t[l][r] = solve(s, l+1, r-1);
//         }

//         // Otherwise, it's not a palindrome
//         return t[l][r] = false;
//     }
    
//     string longestPalindrome(string s) {
//         int n = s.length(); // Length of input string
        
//         int maxlen = INT_MIN;   // Stores maximum length of palindrome found so far
//         int startingIndex = 0;  // Starting index of the longest palindrome
        
//         memset(t, -1, sizeof(t)); // Initialize DP table with -1 (uncomputed)

//         // Try all possible substrings s[i..j]
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
                
//                 if (solve(s, i, j)) { // If substring s[i..j] is palindrome
//                     if (j - i + 1 > maxlen) { // Check if its length is larger than max found so far
//                         startingIndex = i;    // Update starting index
//                         maxlen = j - i + 1;   // Update max length
//                     }
//                 }
//             }
//         }

//         // Return the longest palindrome substring found
//         return s.substr(startingIndex, maxlen);
//     }
// };

class Solution {
  public:
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n == 0) return "";
        
        int start = 0, maxLen = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = l;
                }
                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);     // Odd-length palindrome
            expand(i, i + 1); // Even-length palindrome
        }

        return s.substr(start, maxLen);
    }
};

