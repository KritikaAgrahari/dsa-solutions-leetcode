class Solution {

    //s[(i+1)%n]-points to 0 index as circular array
    //tc = O(n)
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        
        int maxdiff=0;
        for(int i=0; i<nums.size(); i++){
            maxdiff = max(maxdiff,abs(nums[i]-nums[(i+1)%n]));
        }
        return maxdiff;
    }
};