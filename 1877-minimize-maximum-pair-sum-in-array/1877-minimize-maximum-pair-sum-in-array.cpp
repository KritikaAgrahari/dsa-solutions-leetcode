class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int maxPairSum=0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        while(i<j){
            maxPairSum=max(maxPairSum,nums[i]+nums[j]);
        i++;
        j--;
        }
        return maxPairSum;
    }
};