class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
       
        // Sort both arrays
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        std::vector<int> result;
        int i = 0, j = 0;
        
        // Use two pointers to find intersections
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                // Skip duplicates
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
        }
        
        return result;
    }


int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    
    std::vector<int> result = solution.intersection(nums1, nums2);
    
    std::cout << "Intersection: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
};
