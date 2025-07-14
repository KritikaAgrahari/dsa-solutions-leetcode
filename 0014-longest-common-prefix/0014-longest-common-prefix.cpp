class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = ""; 

        for (int i = 0; i < strs[0].size(); i++) {

            for (int j = 0; j < strs.size(); j++) {

                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return result; // Mismatch → return prefix found so far
                }
            }

            result += strs[0][i];
        }

        return result; 
    }
};
