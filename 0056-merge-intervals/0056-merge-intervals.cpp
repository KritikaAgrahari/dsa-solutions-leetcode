class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // If there is only one interval, return it directly
        if(intervals.size() <= 1)
            return intervals;

        // Sort intervals according to the starting value
        sort(intervals.begin(), intervals.end());

        // Vector to store the final merged intervals
        vector<vector<int>> result;

        // Take the first interval as the current interval
        vector<int> newInterval = intervals[0];

        // Add it to the result
        result.push_back(newInterval);

        // Traverse all intervals
        for(auto interval : intervals)
        {
            // If current interval overlaps with newInterval
            if(interval[0] <= newInterval[1])
            {
                // Extend the ending point if needed
                newInterval[1] = max(newInterval[1], interval[1]);

                // Update the last interval stored in result
                result.back() = newInterval;
            }
            else
            {
                // No overlap, start a new interval
                newInterval = interval;

                // Add this interval to the answer
                result.push_back(newInterval);
            }
        }

        // Return all merged intervals
        return result;
    }
};