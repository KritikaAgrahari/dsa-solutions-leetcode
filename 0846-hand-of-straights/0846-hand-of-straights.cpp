class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();  

        // If the total number of cards can't be divided into equal groups of groupSize, return false
        if (n % groupSize) {
            return false;
        }

        // Map to store frequency of each card (sorted by default using map)
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;  // Count occurrences of each card
        }

        // Process all cards by forming consecutive groups
        while (!mp.empty()) {
            int curr = mp.begin()->first;  // Get the smallest available card

            // Try to build a group of size groupSize starting from the smallest card
            for (int i = 0; i < groupSize; i++) {
                // If the current card (curr + i) is not available, we can't form a group
                if (mp[curr + i] == 0) {
                    return false;
                }

                // Use one card of value (curr + i)
                mp[curr + i]--;

                // If count becomes 0, remove the card from the map
                if (mp[curr + i] == 0) {
                    mp.erase(curr + i);
                }
            }
        }

        // All cards have been successfully grouped
        return true;
    }
};
