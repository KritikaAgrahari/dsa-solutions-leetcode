class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int sum=0;
        int n=nums.size();
        for (int i=0; i<n ; i++){
            sum=sum+nums[i];
        }
        int cs=0;
        for (int i=0; i<n; i++){
            int ls=cs;
            int rs=sum-cs-nums[i];
            if(ls==rs) return i;
                    cs += nums[i];

        }
        
        return -1;
    }
};