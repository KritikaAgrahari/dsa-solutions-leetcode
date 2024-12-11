class Solution {

public:
static bool comparator(int &a, int &b){
    return a%2 < b%2;
}
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comparator);
        return nums;
        
    }
};
