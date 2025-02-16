//tc can be decreased using booths algo
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k>1){
            sort(s.begin(),s.end());
        }
        int n =s.size();
        string result=s;
        for (int i=1; i<=n-1; i++){
            string temp=s.substr(i)+s.substr(0,i);
                    result= min (result,temp);

        }
        return result;
    }
};


// class Solution {
// public:
//     string orderlyQueue(string s, int k) {
//         if (k > 1) {
//             sort(s.begin(), s.end());
//             return s;
//         }
        
//         int n = s.size(), best = 0;
//         string doubled = s + s;  // Simulate circular rotation
        
//         for (int i = 1, j = 0; i < n; i++) {
//             if (doubled[i] < doubled[best]) best = i;
//             else if (doubled[i] == doubled[best]) {
//                 for (j = 1; j < n && doubled[i + j] == doubled[best + j]; j++);
//                 if (j < n && doubled[i + j] < doubled[best + j]) best = i;
//             }
//         }

//         return doubled.substr(best, n);
//     }
// };
