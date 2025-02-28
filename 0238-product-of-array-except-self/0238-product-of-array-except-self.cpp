// class Solution {
// public:
//TIME LIMITS EXCEED
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();

//         vector<int>result(n,1);

//         for (int i=0; i<n;i++){

//            for (int j=0; j<n; j++){
//                 if (i!=j){
//                     result[i] *=nums[j];
//                 }
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Compute prefix product
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        // Compute suffix product and multiply with prefix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        
        return result;
    }
};
