class Solution {
public:
    int trailingZeroes(int n) {

        int count = 0;

        while(n > 0) {

            n = n / 5;      // Count multiples of 5,25,125,...

            count += n;
        }

        return count;
    }
};