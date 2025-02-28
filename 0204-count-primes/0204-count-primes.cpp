class Solution {
public:
    int countPrimes(int n) {
        // If n is 2 or less, there are no prime numbers
        if (n <= 2) return 0;

        // Create a boolean vector of size n, initialized to true
        vector<bool> isPrime(n, true);
        
        // 0 and 1 are not prime numbers
        isPrime[0] = isPrime[1] = false;

        // Iterate from 2 to sqrt(n) (optimized Sieve of Eratosthenes)
        for (int i = 2; i * i < n; ++i) {
            // If i is already marked as non-prime, skip it
            if (!isPrime[i]) continue;

            // Mark all multiples of i as non-prime
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }

        // Count and return the number of primes (true values in isPrime array)
        return count(isPrime.begin(), isPrime.end(), true);
    }
};
