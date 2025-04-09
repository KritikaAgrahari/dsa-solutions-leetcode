class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums) {
            if (num < k) return -1; // impossible case
        }

        unordered_set<int> aboveK;
        for (int num : nums) {
            if (num > k) {
                aboveK.insert(num);
            }
        }

        return aboveK.size(); // each unique value above k requires 1 operation
    }
};
