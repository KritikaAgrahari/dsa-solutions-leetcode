// class Solution {
// public:
//     int minSwaps(string s) {

//         int count=0;
//         for(int i=0; i<s.length(); i++){
           
//             if(s[i]=='['){
//                 count++;
//             }
//             else if(count>0){
//                 count--;
//             }
//         }
//         return (count+1)/2;
        
//     }
// };


class Solution {
public:
    int minSwaps(string s) {

        stack<char>st;
        int n=s.length();
        for(int i=0; i<n ; i++){
if(s[i]=='['){
    st.push(s[i]);
}

else if(!st.empty()){
    st.pop();
}
        }
        return (st.size()+1)/2;
    }
    };