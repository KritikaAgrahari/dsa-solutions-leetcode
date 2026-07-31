class Solution {
public:
    int getSum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_set<int> visited;

        while (n != 1 && visited.count(n) == 0) {
            visited.insert(n);
            n = getSum(n);
        }

        return n == 1;
    }
};