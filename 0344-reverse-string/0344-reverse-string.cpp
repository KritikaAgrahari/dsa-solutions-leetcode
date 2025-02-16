// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         stringstream ss(s);
//         int n=s.length();
//         string token ="";
//         string result="";
//         while (ss>>token){
//             reverse(begin(token),end(token));
//             result +=token + "";
//         }
//         return result.substr(0,result.length()-1);
//     }
// };

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
