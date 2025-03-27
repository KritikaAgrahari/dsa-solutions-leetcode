#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Step 1: Find the dominant element
        for (int num : nums) {
            freq[num]++;
        }

        int dominant = -1, total_count = 0;
        for (auto& [key, value] : freq) {
            if (value * 2 > n) {
                dominant = key;
                total_count = value;
                break;
            }
        }

        // Step 2: Iterate and find the minimum valid split
        int left_count = 0, right_count = total_count;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                left_count++;
                right_count--;
            }
            if (left_count * 2 > (i + 1) && right_count * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};
