class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0; // Edge case for 0
        
        int low = 1, high = x, ans = 0; 
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoids overflow
            long long sqr = (long long)mid * mid; // Prevent overflow
            
            if (sqr == x) return mid; 
            else if (sqr < x) {
                ans = mid; // Store the answer
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
        return ans; // Returns the floor value of sqrt(x)
    }
};
