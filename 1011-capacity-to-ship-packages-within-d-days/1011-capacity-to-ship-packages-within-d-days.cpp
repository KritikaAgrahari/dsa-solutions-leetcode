class Solution {
public:
    int findDays(vector<int>& weights, int cap) {
        int days = 1, load = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] + load > cap) {
                days += 1;  // Fixed typo here (was 'day' instead of 'days')
                load = weights[i];  // Reset load to current weight
            } else {
                load += weights[i];  // Accumulate the load
            }
            
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());  // Get max weight
        int high = accumulate(weights.begin(), weights.end(), 0);  // Get sum of weights
        
        while(low <= high) {
            int mid = low + (high - low) / 2;  // Avoid overflow in computing mid
            int numberOfDays = findDays(weights, mid);

            if(numberOfDays <= days) {
                high = mid - 1;  // Try to minimize capacity
            } else {
                low = mid + 1;  // Increase capacity
            }
        }

        return low;  // Low will hold the minimum capacity
    }
};
