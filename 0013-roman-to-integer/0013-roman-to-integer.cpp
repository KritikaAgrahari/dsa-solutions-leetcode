class Solution { //0(n) chatgpt
public:
    int romanToInt(string s) {
        // Create a map to store the Roman numeral values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, 
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        
        // Loop through the string
        for (int i = 0; i < s.size(); i++) {
            // If the current character is smaller than the next character, subtract it
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            }
            // Otherwise, add it
            else {
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};
