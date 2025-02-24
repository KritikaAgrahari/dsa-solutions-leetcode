// class Solution {
// public:
//     int hammingWeight(int n) {
//         int count = 0;
//         while(n){
//             count += n%2;
//             n=n/2;
//         }

//         return count;
//     }
// };


class Solution {
public:
    int hammingWeight(int n) {
       

        return __builtin_popcount(n);
    }
};
