class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int result = 0;
        sort(piles.begin(), piles.end());
        int b=0;
        int m=n-2;
        while(m>b){
          result += piles[m];
            m -=2;
            b++;
        }
        return result;
        
    }
};