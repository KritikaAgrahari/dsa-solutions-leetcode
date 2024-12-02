class Solution {

public:
    string countAndSay(int n) {
        // Base case: If n is 1, the sequence is just "1"
        if (n == 1) return "1";
        
        // Recursively get the count-and-say sequence for n-1
        string say = countAndSay(n - 1);
        
        // Initialize an empty string to store the result
        string result = "";
        
        // Iterate through the string 'say' to count consecutive characters
        for (int i = 0; i < say.length(); i++) {
            // Get the current character
            char ch = say[i];
            
            // Initialize a count for the current character
            int count = 1;
            
            // Check for consecutive occurrences of the same character
            // While the next character is the same, increment the count and move the index
            while (i < say.length() - 1 && say[i] == say[i + 1]) {
                count++;   // Increment the count
                i++;       // Move to the next character
            }
            
            // Append the count and the character to the result
            result += to_string(count) + string(1, ch);
        }
        
        // Return the result string after processing all characters
        return result;
    }
};
