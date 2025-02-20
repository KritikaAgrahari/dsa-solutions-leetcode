class Solution {
public:
    long long minimumSteps(string s) {
        int n= s.length();
        int count=0;
        sort(s.begin(),s.end());
        int result=0;
        for (int i=0; i<=n; i++){
            if (s[i]==1){
                count++;

            }
            result = result+count;
        }
        return result;
    }
};