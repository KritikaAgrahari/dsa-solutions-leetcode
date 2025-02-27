class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for (int i = 0; i < stones.length(); i++) {
            for (int j = 0; j < jewels.length(); j++) {
                if (stones[i] == jewels[j]) {
                    count++;
                    break;  // No need to check further if match is found
                }
            }
        }
        return count;
    }
};
