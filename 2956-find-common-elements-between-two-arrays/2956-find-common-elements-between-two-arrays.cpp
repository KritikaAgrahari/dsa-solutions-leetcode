class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s1;      // Store unique elements of nums1
        unordered_set<int> s2;      // Store unique elements of nums2

        // Insert all elements of nums1 into set s1
        for(int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }

        // Insert all elements of nums2 into set s2
        for(int i = 0; i < nums2.size(); i++) {
            s2.insert(nums2[i]);
        }

        int count1 = 0;    // Counts elements of nums1 present in nums2
        int count2 = 0;    // Counts elements of nums2 present in nums1

        // Check every element of nums1
        for(int i = 0; i < nums1.size(); i++) {

            if(s2.find(nums1[i]) != s2.end()) {   // If element exists in nums2
                count1++;
            }
        }

        // Check every element of nums2
        for(int i = 0; i < nums2.size(); i++) {

            if(s1.find(nums2[i]) != s1.end()) {   // If element exists in nums1
                count2++;
            }
        }

        return {count1, count2};   // Return both answers
    }
};