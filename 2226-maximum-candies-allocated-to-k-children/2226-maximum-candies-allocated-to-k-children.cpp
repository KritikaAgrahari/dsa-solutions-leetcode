class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = max_element(candies.begin(), candies.end());
        int ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;

            for (int candy : candies) {
                count += candy / mid;  // Count how many children can get `mid` candies
            }

            if (count >= k) {  // We can distribute to at least k children
                ans = mid;  // Store valid answer
                left = mid + 1;  // Try larger `mid`
            } else {
                right = mid - 1;  // Try smaller `mid`
            }
        }
        return ans;
    }
};
