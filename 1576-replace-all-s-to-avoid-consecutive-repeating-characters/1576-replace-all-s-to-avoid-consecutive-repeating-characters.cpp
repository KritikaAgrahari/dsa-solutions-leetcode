class Solution {
public:
    string modifyString(string s) {
        int n=s.length();
        for (int i=0;i<n; i++){
            if (s[i]=='?'){
                for (char ch='a';ch<='z';ch++){
if ((i > 0 && s[i - 1] == ch) || (i < n - 1 && s[i + 1] == ch)) {                    continue;
                    }
                    s[i]=ch;
                    break;
                }
            }
        }
        return s;
    }
};