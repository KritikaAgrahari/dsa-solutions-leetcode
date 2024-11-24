class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";  // Special case for zero
        
        string rem;
        while (n != 0) {
            int remainder = n % -2;  // Find remainder when divided by -2
            n /= -2;  // Perform integer division by -2
            
            if (remainder < 0) {
                remainder += 2;  // Adjust remainder to ensure it's non-negative
                n += 1;  // Adjust n to account for remainder being negative
            }
            
            rem += (remainder == 1) ? '1' : '0';  // Add the remainder to the result
        }
        
        reverse(rem.begin(), rem.end());  // Reverse to get the correct binary representation
        return rem;
    }
};
