class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result; // Result vector will store final merged numbers (acts like a stack)

        // Process elements from left to right using a traditional for loop
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i]; // Take the current number from nums

            // Keep merging as long as result is not empty AND last element is NOT coprime with current num
            while (!result.empty()) {
                int prev = result.back(); // Get the last element from result (like top of stack)
                int curr = num;           // Current number to check with prev
                
                int GCD = gcd(prev, curr); // Find GCD of prev and curr
                if (GCD == 1) { // If they are coprime, stop merging
                    break;
                }

                result.pop_back(); // Remove last element because it will be merged
                int LCM = (prev / GCD) * curr; // Compute LCM carefully to avoid overflow

                num = LCM; // Replace num with the merged LCM value and recheck with previous elements
            }

            result.push_back(num); // Push the (possibly merged) number into result
        }

        return result; // Return the final vector after all merges
    }
};
