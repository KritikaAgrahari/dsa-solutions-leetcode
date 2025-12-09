class Solution {
public:
    int M = 1e9 + 7;   // Modulo value for result

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp_left;   // Counts of numbers seen so far (left side)
        unordered_map<int, int> mp_right;  // Counts of numbers yet to be seen (right side)

        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            mp_right[nums[i]]++;           // Count occurrences of each number
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];             // Current number

            mp_right[num]--;               // Remove current number from right side

            int left  = mp_left[num * 2];  
            int right = mp_right[num * 2]; 

            result = (result + (1LL * left * right)) % M;

            mp_left[num]++;                
        }

        return result;
    }
};
