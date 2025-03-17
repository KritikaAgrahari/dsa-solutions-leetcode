// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         unordered_map<int,int>frequency;
//         for (int i=0; i<nums.size(); i++){
//             frequency[nums[i]]++;
//         }

//         for (auto it = frequency.begin(); it != frequency.end(); ++it) {
//             if(it->second % 2!=0) return false;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(N log N)
        for (int i = 0; i < nums.size(); i += 2) { // O(N)
            if (nums[i] != nums[i + 1]) return false;
        }
        return true;
    }
};
