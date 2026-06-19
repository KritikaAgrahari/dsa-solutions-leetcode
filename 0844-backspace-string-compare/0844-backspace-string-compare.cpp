class Solution {
public:
    string build(string str) {
        string res;

        for (char c : str) {
            if (c == '#') {
                if (!res.empty()) res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};