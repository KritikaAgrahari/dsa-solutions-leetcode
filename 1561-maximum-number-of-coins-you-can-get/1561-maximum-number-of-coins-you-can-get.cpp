// class Solution {
// public:
//     int maxCoins(vector<int>& piles) {
//         int n = piles.size();
//         int result = 0;
//         sort(piles.begin(), piles.end());
//         int b=0;
//         int m=n-2;
//         while(m>b){
//           result += piles[m];
//             m -=2;
//             b++;
//         }
//         return result;
        
//     }
// };



class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int result = 0;
        sort(piles.begin(), piles.end());
       for(int m=n/3; m<n ; m+=2){
        result += piles[m];
       }
        
        return result;
        
    }
};