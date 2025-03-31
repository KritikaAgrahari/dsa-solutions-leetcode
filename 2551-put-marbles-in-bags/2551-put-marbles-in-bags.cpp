class Solution {
public:
    long long putMarbles(std::vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;  // Only one bag, same max and min score.

        std::vector<int> pairSum;
        for (int i = 0; i < n - 1; i++) {
            pairSum.push_back(weights[i] + weights[i + 1]);
        }

        std::sort(pairSum.begin(), pairSum.end());

        long long minScore = 0, maxScore = 0;
        for (int i = 0; i < k - 1; i++) {
            minScore += pairSum[i];                       // Take smallest (k-1) sums
            maxScore += pairSum[n - 2 - i];              // Take largest (k-1) sums
        }

        return maxScore - minScore;
    }
};