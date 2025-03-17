class Solution {
public:
    long long minEnd(int n, int x) {
        long long number=x;
        for (int i=1; i<n;i++){
            number=(number+1) | x; 
        }
        return number;
    }
};