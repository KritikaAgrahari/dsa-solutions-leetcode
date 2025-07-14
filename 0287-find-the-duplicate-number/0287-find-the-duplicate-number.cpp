class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i=0; i<nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it :mp){
        //     if(it.second>1)
        //     return it.first;
        // }
        // return -1

int slow=nums[0];
int fast= nums[0];

slow=nums[slow];
fast= nums[nums[fast]];

while(slow!=fast){
    slow=nums[slow];
    fast=nums[nums[fast]];
}
while(slow!=fast){
    slow=nums[slow];
    fast=nums[fast];
}
        
        return fast;
    }
};