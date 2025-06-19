class Solution {
public:
int M=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        unordered_map<char,int>mp;
        for(char &ch:s){
            mp[ch]++;
        }
        for(int count=1; count<=t; count++){
            unordered_map<char,int>temp;
            for(auto &it : mp){
                char ch=it.first;
                int freq=it.second;

                if(ch!='z'){
                    temp[ch+1]=(temp[ch+1]+freq)%M;
                }
                else {
                    temp['a']=(temp['a']+freq)%M;
                    temp['b']=(temp['b']+freq)%M;

                }
            }
            mp=move(temp);
        }
        int result=0;
        for(auto &it : mp){
            result = (result +it.second)%M;
        }
return result;
    }
};