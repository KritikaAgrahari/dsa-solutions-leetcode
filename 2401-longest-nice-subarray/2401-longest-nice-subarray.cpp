class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int count=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] && nums[i+1] == 0){
                count ++;
            }
        }
        return count;
    }
};