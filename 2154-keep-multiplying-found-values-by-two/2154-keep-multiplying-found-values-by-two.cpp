class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
          unordered_set<int> s(nums.begin(), nums.end()); // fast lookup
        
        while (s.count(original)) {
            original *= 2;  // multiply when found
        }
        
        return original;
        
    }
};