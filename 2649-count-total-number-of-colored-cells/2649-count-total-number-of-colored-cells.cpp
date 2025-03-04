// class Solution {
// public:
//     long long coloredCells(int n) {
//         long long cells=1;
//         int t=1;
//         while(t<=n){
//             cells +=4*(t-1);
//             t++;
//         }
//         return cells;
//     }
// };

// class Solution {
// public:
//     long long coloredCells(int n) {
      
//         return 1+(2*(long long )(n-1)*n);
//     }
// };
class Solution {
public:
    long long coloredCells(int n) {
        return 1LL * n * n + (n - 1LL) * (n - 1);
    }
};
