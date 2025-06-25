class Solution {
public:
    int minSwaps(string s) {

        int count=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='['  && s[i+1]==']'){
                continue;
            }
            else if(s[i]=='['){
                count++;
            }
        }
        return (count+1)/2;
        
    }
};