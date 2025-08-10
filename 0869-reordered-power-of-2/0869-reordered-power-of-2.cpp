class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        for (int i = 0; i < 31; i++) { // 2^0 to 2^30
            int power = 1 << i;
            string t = to_string(power);
            sort(t.begin(), t.end());
            if (s == t) return true;
        }
        return false;
    }
};
