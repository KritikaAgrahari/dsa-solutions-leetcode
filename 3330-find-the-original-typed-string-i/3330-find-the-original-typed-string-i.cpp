class Solution {
public:
    int possibleStringCount(string word) {
        int n =word.size();
        int count=1; //may be no mistake is made while typing
        for(int i=0; i<n; i++){
            if(i>0 && word[i]== word[i-1])
            count++;
        }
        return count;
    }
};