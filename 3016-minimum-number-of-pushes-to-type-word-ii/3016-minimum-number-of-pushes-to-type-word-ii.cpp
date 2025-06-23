class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();

        vector<int>mp(26,0);

        for(int i=0; i<n; i++){
            mp[word[i]-'a']++;
        }

        sort(mp.begin(),mp.end(),greater<int>()); //for sorting in decreasing order
         int result =0;
         for(int i=0 ; i<26 ; i++){
            int freq= mp[i];
            int press = i/8+1;
            result += freq*press;
         }
         return result;
        
    }
};