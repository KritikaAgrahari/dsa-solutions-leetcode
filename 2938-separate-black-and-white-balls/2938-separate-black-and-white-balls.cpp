class Solution {
public:
    long long minimumSteps(string s) {
        int n= s.length();
        int black=0;
        
        long long swap=0;
        for (int i=0; i<n; i++){
            if (s[i]=='0'){
                swap += black;

            }
            else{
                black++;
            }
            
        }
        return swap;
    }
};