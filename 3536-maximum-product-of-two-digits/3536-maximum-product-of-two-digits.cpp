
class Solution {
public:
    int maxProduct(int n) {

        int max1 = 0, max2 = 0;  // Store the largest and second largest digits

        while (n > 0) {          // Repeat until all digits are extracted

            int rem = n % 10;    // Extract the last digit of n

            if (rem >= max1) {   // Check if current digit is greater than or equal to largest digit

                max2 = max1;     // Move the previous largest digit to second largest

                max1 = rem;      // Update the largest digit with current digit
            }

            else if (rem > max2) { // If not largest, check whether it is second largest

                max2 = rem;      // Update the second largest digit
            }

            n = n / 10;          // Remove the last digit from n
        }

        return max1 * max2;      // Multiply the two largest digits and return the result
    }
};
