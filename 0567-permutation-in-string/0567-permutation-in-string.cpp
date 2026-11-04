class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if(n > m) {
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Step 1: Store the frequency of characters in s1
        for(int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
        }

        // Step 2: Create the first window in s2
        for(int i = 0; i < n; i++) {
            freq2[s2[i] - 'a']++;
        }

        // Step 3: Compare the frequency arrays
        if(freq1 == freq2) {
            return true;
        }

        // Step 4: Slide the window through s2
        for(int i = n; i < m; i++) {

            // Remove the character leaving the window
            freq2[s2[i - n] - 'a']--;

            // Add the new character entering the window
            freq2[s2[i] - 'a']++;

            // Check whether both frequency arrays match
            if(freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};