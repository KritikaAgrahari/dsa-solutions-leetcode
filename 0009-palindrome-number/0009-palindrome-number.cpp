class Solution { 
public:
    bool isPalindrome(int x) {
        // If x is negative or ends in 0 (but isn't 0), it's not a palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
            
        }

        int reversedHalf = 0;
        // Reverse the last half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Check if the first half is equal to the reversed second half
        // Also, consider the case when the number has an odd number of digits
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
