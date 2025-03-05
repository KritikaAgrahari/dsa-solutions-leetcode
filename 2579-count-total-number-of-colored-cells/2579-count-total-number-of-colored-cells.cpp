class Solution {
public:
    long long coloredCells(int n) {
        long long cells=1;
        int t=1;
        while(t<=n){
            cells +=4*(t-1);
            t++;
        }
        return cells;
    }
};