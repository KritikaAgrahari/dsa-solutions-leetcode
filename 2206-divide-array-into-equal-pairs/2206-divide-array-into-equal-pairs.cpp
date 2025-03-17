class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>frequency;
        for (int i=0; i<nums.size(); i++){
            frequency[nums[i]]++;
        }

        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            if(it->second % 2!=0) return false;
        }
        return true;
    }
};