class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1i = 0, i = 0;
        int w2i = 0, j = 0;

        while (w1i < word1.size() && w2i < word2.size()) {
            if (word1[w1i][i] != word2[w2i][j]) {
                return false;
            }

            // Move to the next character in the current string
            i++;
            j++;

            // If we reach the end of a string in word1, move to the next string
            if (i == word1[w1i].length()) {
                i = 0;
                w1i++;
            }

            // If we reach the end of a string in word2, move to the next string
            if (j == word2[w2i].length()) {
                j = 0;
                w2i++;
            }
        }

    if (w1i==word1.size()  && w2i==word2.size()){
        return true;
    }
    return false;
    }
};