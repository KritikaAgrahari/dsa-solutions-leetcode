class Solution {
public:
    bool isPowerOfThree(int n) {
        // The largest power of 3 that fits in a 32-bit signed integer is 3^19 = 1162261467
        // Any power of 3 must divide this number evenly (i.e., without a remainder)
        // So if n is a power of 3, then 1162261467 % n == 0
        return n > 0 && 1162261467 % n == 0;
    }
};
