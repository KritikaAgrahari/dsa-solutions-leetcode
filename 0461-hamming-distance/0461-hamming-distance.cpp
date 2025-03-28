// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int result = (x ^ y);
//         int count = 0;  // Initialize count

//         while (result != 0) {
//             count += result & 1;  // Check last bit
//             result >>= 1;   // Right shift result
//         }

//         return count;  // Return count instead of result
//     }
// };

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);  // Counts the number of 1s in (x XOR y)
    }
};
