#include <algorithm> // for gcd, min_element, max_element

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = *min_element(nums.begin(), nums.end()); // smallest element
        int b = *max_element(nums.begin(), nums.end()); // largest element
        
        // Euclidean algorithm for GCD
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
