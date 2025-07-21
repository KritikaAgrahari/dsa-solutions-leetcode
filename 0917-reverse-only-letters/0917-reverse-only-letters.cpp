class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-letter characters from the left
            if (left < right && !isalpha(s[left])) {
                left++;
            }

            // Skip non-letter characters from the right
            else if  (left < right && !isalpha(s[right])) {
                right--;
            }

            // Swap the letters
            else{
            swap(s[left], s[right]);
            left++;
            right--;
            }
        }

        return s;
    }
};
