class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_map;
        for(int i=0; i<matches.size(); i++){
            int loser=matches[i][1];
            lost_map[loser]++;
        }

        vector<int>never_lose;
        vector<int>lose_once;

        for(int i=0; i<matches.size(); i++){
            int winner=matches[i][0];
            int loser=matches[i][1];
            if(lost_map.find(winner)==lost_map.end()){
                never_lose.push_back(winner);
                lost_map[winner]=2;
            }

            if(lost_map[loser]==1){
                lose_once.push_back(loser);
            }
        }
        sort(never_lose.begin(),never_lose.end());
        sort(lose_once.begin(),lose_once.end());
        return{never_lose,lose_once};
        
    }
};