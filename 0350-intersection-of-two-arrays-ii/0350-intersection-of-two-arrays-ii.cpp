class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> result;

        // Store the frequency of each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]]++;
        }

        // Check elements in nums2 and reduce frequency accordingly
        for (int i = 0; i < nums2.size(); i++) {
            if (mp[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                mp[nums2[i]]--;  // Decrease count to avoid duplicates
            }
        }

        return result;
    }
};
