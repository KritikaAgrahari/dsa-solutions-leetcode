
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        vector<string> result;

        // Break into words using stringstream
        while (ss >> token) {
            result.push_back(token);
        }

        // Reverse the words
        reverse(result.begin(), result.end());

        // Join the words
        string reversedString;
        for (int i = 0; i < result.size(); i++) {  // Use result.size() instead of n
            reversedString += (i > 0 ? " " : "") + result[i];  
        }
        return reversedString;  // Moved inside the function
    }
};
