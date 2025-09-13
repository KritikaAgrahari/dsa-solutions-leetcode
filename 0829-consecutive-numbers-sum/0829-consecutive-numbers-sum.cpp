class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        // Count odd divisors of n
        for (int i = 1; (long long)i * i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 == 1) count++;            // i is odd divisor
                if ((n / i) % 2 == 1 && i != n / i) count++; // paired divisor
            }
        }
        return count;
    }
};
