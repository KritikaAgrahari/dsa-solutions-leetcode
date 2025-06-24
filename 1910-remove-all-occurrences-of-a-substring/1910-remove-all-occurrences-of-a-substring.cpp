class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int n=part.length();
        string result="";

        for(int i=0; i<s.length();i++){
            result.push_back(s[i]);

            if(result.length()>=n && result.substr(result.length()-n)==part){
                result.erase(result.length()-n);
            }
        }
return result;
    }
};