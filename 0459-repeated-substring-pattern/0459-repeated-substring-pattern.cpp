class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n= s.length();
        for (int i=n/2; i>=1;i--){
            if (n%i==0){
                int times= n/i;
                string pattern = s.substr(0,i);
                string newptn = "";
                
            
            while (times--){
                newptn += pattern;
            }
            
            if (newptn == s){
                return true;
             } }
        }
        return false;
    }
};



//EASIEST WAY TO APPROACH 
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         string doubled = s + s;  // Double the string
//         return doubled.substr(1, doubled.size() - 2).find(s) != string::npos;
//     }
// };



