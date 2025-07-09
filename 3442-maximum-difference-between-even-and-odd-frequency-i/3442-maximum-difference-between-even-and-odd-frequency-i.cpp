class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();

        vector<int>freq(26,0);

       for (int i = 0; i < n; i++) { // Count frequency of characters in string s
            char ch = s[i];
            freq[ch - 'a']++;
        }
int oddfreq=0;
int evenfreq=n+1;
        for(int i=0; i<n ; i++){
            if(freq[i]==0) continue;

            if (freq[i]%2 ==0){
                evenfreq= min(evenfreq,freq[i]);
            }
            else{
             oddfreq= max(oddfreq,freq[i]);
            }
        }
         return oddfreq-evenfreq;
    }
};