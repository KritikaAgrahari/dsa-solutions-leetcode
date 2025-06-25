class Solution {
public:
    int minSwaps(string s) {

        int count=0;
        for(int i=0; i<s.length(); i++){
           
            if(s[i]=='['){
                count++;
            }
            else if(count>0){
                count--;
            }
        }
        return (count+1)/2;
        
    }
};