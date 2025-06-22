class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int result = 0;

        // Traditional for loop for traversing 'words'
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            string reversedWord = word;
            swap(reversedWord[0], reversedWord[1]);

            if(mp[reversedWord] > 0) {
                result += 4;
                mp[reversedWord]--;
            } else {
                mp[word]++;
            }
        }

        // Traditional for loop for traversing map
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            string word = it->first;
            int count = it->second;

            if(word[0] == word[1] && count > 0) {
                result += 2;
                break;
            }
        }

        return result;
    }
};
