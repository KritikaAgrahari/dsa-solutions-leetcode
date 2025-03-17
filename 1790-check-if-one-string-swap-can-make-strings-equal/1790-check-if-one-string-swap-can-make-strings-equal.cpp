class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int diffcount=0;
        int firstindex=0;
        int secondindex=0;
        if(s1==s2) return true;
        for (int i=0; i<n; i++){
            if (s1[i]!=s2[i]) {
                 diffcount++;
            
        if (diffcount>2){
           return false;
        }
        else if (diffcount==1){
            firstindex=i;
        }
        else {
                        secondindex=i;
        }
        }
        }
return s1[firstindex]==s2[secondindex] && s1[secondindex]==s2[firstindex];
        
    }
};