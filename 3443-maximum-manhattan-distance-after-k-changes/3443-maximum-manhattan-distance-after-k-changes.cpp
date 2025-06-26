class Solution {
public:
    int maxDistance(string s, int k) {
        // Variable to store the maximum Manhattan Distance observed
        int maxMD = 0;

        // Counters to track movement in each direction
        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;

        // Traverse through the string which contains directions
        for(int i = 0; i < s.length(); i++) {

            // Increment the corresponding direction counter
            if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;
            else if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;

            // Compute current Manhattan distance: |E-W| + |N-S|
            int currMD = abs(east - west) + abs(north - south);

            // Total steps taken so far (i is 0-indexed, so i+1 steps)
            int steps  = i + 1;

            // Wasted steps = steps taken - current Manhattan distance
            // These are extra moves that cancel each other out
            int wasted = steps - currMD;

            int extra = 0;
            // If there are wasted steps, try to utilize up to 2*k of them
            // Because each reversal of one wasted move takes 2 operations
            if(wasted != 0) {
                extra = min(2 * k, wasted);
            }

            // Add the "usable" extra moves to the current MD
            int finalCurrentMD = currMD + extra;

            // Update maxMD if this is the largest so far
            maxMD = max(maxMD, finalCurrentMD);
        }

        // Return the maximum possible Manhattan Distance
        return maxMD;
    }
};
