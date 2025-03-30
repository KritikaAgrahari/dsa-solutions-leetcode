class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n=s.size();
        unordered_map<char,int>store;
        for(int i=0; i<n; i++){
            store[s[i]]=i;
        }
        int maxi=0;
        int prev=-1;
        vector<int>result;
        for(int i=0; i<n; i++){
            maxi=max(maxi,store[s[i]]);
            if(maxi==i) {
                result.push_back(i-prev);
                prev=maxi;
                }

        }
        
    return result;
        
    }
};