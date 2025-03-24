#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // Sort meetings by start time
        int end = 0, result = 0;
        int n = meetings.size();

        for (int i = 0; i < n; i++) {
            if (meetings[i][0] > end + 1) {  // Gap between meetings
                result += meetings[i][0] - end - 1;
            }
            end = max(end, meetings[i][1]); // Extend the meeting end time
        }

        // Count remaining free days after last meeting
        if (end < days) {
            result += days - end;
        }

        return result;
    }
};
