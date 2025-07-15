class Solution {
public:
    string convert(string s, int numRows) {
        // If there's only one row or the string is shorter than number of rows, return as is
        if (numRows == 1 || s.length() <= numRows) return s;

        // Create a vector to store strings for each row
        vector<string> rows(min(numRows, int(s.length())));

        // Start from the first row
        int currRow = 0;

        // Direction flag: true = moving down, false = moving up
        bool goingDown = false;

        // Traverse each character in the string
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];               // Get current character
            rows[currRow] += c;          // Add character to the current row

            // Change direction if we reach top or bottom row
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;

            // Move to the next row based on direction
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows to form the final result string
        string result = "";
        for (int i = 0; i < rows.size(); i++) {
            result += rows[i];           // Append each row's string to result
        }

        // Return the final converted zigzag string
        return result;
    }
};
