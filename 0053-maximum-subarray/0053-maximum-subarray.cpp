#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LLONG_MIN; // Initialize to the smallest value
        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i]; // Add current element to the sum
            
            if (sum > maxi) { 
                maxi = sum; // Update maximum if the current sum is greater
            }
            
            if (sum < 0) { 
                sum = 0; // Reset sum to zero if it becomes negative
            }
        }

        return maxi; // Return the maximum subarray sum
    }
};
