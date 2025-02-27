class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start;
        int y=goal;
          int result = x ^ y;
        int count = 0;

        while (result) {
            result &= (result - 1);  // Removes the rightmost set bit
            count++;
        }

        return count;
    }
};