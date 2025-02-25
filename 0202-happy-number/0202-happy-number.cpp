class Solution {
    //floyd's cycle detection
public:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {  
            slow = getNext(slow);           // Move slow pointer one step
            fast = getNext(getNext(fast));  // Move fast pointer two steps
            
            if (slow == fast) break;  // Exit loop if cycle is detected
        } 

        return slow == 1;  // If loop ends at 1, it's a happy number
    }
};
