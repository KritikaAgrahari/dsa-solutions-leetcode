// class Solution {
// public:
//     int numberOfSteps(int num) {
//         int count =0;
//         while (num>0){
//             if (num % 2 == 0){
//                 num /=2;
//             }
//             else{
//                 num -=1;
//             }
//             count++;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        return __builtin_popcount(num) + 31 - __builtin_clz(num);
    }
};
