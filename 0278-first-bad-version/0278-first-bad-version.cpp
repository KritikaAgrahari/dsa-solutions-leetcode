// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {

public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while (start < end) {  // Binary search loop
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid;  // Move left if mid is bad
            } else {
                start = mid + 1;  // Move right if mid is good
            }
        }
        return start;  // Start will point to the first bad version


    }
};