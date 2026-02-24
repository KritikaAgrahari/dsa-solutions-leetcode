class Solution {
public:
    int binaryGap(int n) {
        int current =0;
        int previous = -1;
        int result =0;
        while(n>0){
            if ((n&1)>0){
                result = (previous !=-1) ? max(result, current-previous) : result,
                previous= current;
            }
            current++;
            n>>=1;
        }
        return result;
    }
};