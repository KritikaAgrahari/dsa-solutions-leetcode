class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for (int i = 0; i < vec2.size(); i++) {
            mp[vec2[i]]++;
        }
    }

    void add(int index, int val) {
        mp[vec2[index]]--;        // Decrease count of current value
        vec2[index] += val;       // Update the value
        mp[vec2[index]]++;        // Increase count of new value
    }

    int count(int tot) {
        int c = 0;
        for (int i = 0; i < vec1.size(); i++) {
            int complement = tot - vec1[i];
            if (mp.find(complement) != mp.end()) {
                c += mp[complement];
            }
        }
        return c;
    }
};
