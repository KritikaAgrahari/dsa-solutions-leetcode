#include <cctype>  // Include this to use isupper()

class Solution {
public:
    bool detectCapitalUse(string word) {
        int no_capital = 0;
        int n = word.size();
        
        for (int i = 0; i < n; i++) {
            if (isupper(word[i])) {  // ✅ Correct function name
                no_capital++;
            }
        }

        return (no_capital == 0 || no_capital == n || (no_capital == 1 && isupper(word[0])));
    }
};
