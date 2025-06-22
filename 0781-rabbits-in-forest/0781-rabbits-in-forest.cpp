class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int>mp;
        //storing answer that the rabbits gave
        for(int i=0; i<n; i++){
            mp[answers[i]]++;

        }
        int total=0;
        for(auto &it : mp){
            int x= it.first;
            int count = it.second;
            int groupsize=(x+1);
            int groups=ceil((double)count/groupsize);

             total += groups * groupsize;


        }
         return total;
    }
};