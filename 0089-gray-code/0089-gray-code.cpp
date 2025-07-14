class Solution {
public:
    // Function to generate n-bit Gray code sequence
    vector<int> grayCode(int n) {
        vector<int> result;  // This vector will store the final Gray code sequence

        int size = 1 << n;   // Compute 2^n using left shift. Total numbers in Gray code sequence

        // Loop from 0 to 2^n - 1
        for (int i = 0; i < size; i++) {
            // Formula to generate Gray code: i XOR (i >> 1)
            // This ensures only one bit changes between consecutive numbers
            result.push_back(i ^ (i >> 1));
        }

        return result;  // Return the generated Gray code sequence
    }
};
