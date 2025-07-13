class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, count = 0;
        int m = players.size(), n = trainers.size();

        while (i < m && j < n) {
            if (players[i] <= trainers[j]) {
                count++;  // match found
                i++; j++;
            } else {
                j++;  // try next trainer
            }
        }

        return count;
    }
};
