// class Solution {
// public:
//     bool divisorGame(int n) {
//         for(int i=0; i<n; i++){
//             if(n%2==0){
//                 return true;
//             }
//         }
//             return false;

//     }

// };

class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0; // Directly return the result
    }
};

