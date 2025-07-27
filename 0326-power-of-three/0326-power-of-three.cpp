// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         // The largest power of 3 that fits in a 32-bit signed integer is 3^19 = 1162261467
//         // Any power of 3 must divide this number evenly (i.e., without a remainder)
//         // So if n is a power of 3, then 1162261467 % n == 0
//         return n > 0 && 1162261467 % n == 0;
//     }
// };


class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base case: negative numbers and 0 are not powers of 3
        if (n <= 0) return false;

        // Base case: 3^0 = 1, so if n == 1, it's a power of 3
        if (n == 1) return true;

        // If n is not divisible by 3, it can't be a power of 3
        if (n % 3 != 0) return false;

        // Recursive step: divide n by 3 and check again
        return isPowerOfThree(n / 3);
    }
};
