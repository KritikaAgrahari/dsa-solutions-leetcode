class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n =nums.size();
        int countp = 0;
        int countn = 0;
        for (int i = 0; i<n ; i++){
            if (nums[i]>0){
                countp++;
            }
            else if(nums[i]<0){
                countn++;
            }

        }
                
        // return (countp>countn) ? countp : countn;
        return max(countp, countn);

    }
};