class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       int n=blocks.size();
       int a =INT_MAX;
       for (int i=0; i<n-k+1; i++){
        string temp = blocks.substr(i,k); //position,size
        int b_min = count(temp.begin(),temp.end(),'W');
        a = min(a,b_min);
        
              }
              return a;

    }
};