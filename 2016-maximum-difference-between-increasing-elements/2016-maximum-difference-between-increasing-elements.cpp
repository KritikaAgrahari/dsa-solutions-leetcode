class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int minel=nums[0];
        int maxdiff=-1;
        for(int j=1; j<n; j++){
            if(nums[j]>minel){
                maxdiff=max(maxdiff,nums[j]-minel);
            }
            else{
                minel=nums[j];
            }
        }
        return maxdiff;
    }
};