class Solution {                 // Defining class (O(1) TC, O(1) SC)
public:
    int maximum69Number (int num) {  
        int place = 0;           // Initializing variable → O(1) TC, O(1) SC
        int index = -1;          // Initializing variable → O(1) TC, O(1) SC
        int temp = num;          // Copy num into temp → O(1) TC, O(1) SC

        while(temp>0) {            // Loop runs once per digit of num → O(d) TC, where d = digits = O(log₁₀(num))
            int remain = temp%10;   // Modulus operation → O(1) TC per iteration, O(1) SC
            if(remain == 6)         // Comparison → O(1) TC, O(1) SC
                index = place;      // Assignment if condition true → O(1) TC, O(1) SC
            
            temp = temp/10;         // Integer division → O(1) TC per iteration, O(1) SC
            place++;                // Increment counter → O(1) TC per iteration, O(1) SC
        }
        
        if(index == -1) return num; // Check if no '6' found → O(1) TC, O(1) SC
        
        return num + 3*pow(10, index); 
        // pow(10, index) takes O(log index) TC (worst case index ≤ d, so O(log d)), O(1) SC
        // Multiplication and addition are O(1) TC
    }
};
