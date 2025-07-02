// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
        
//         sort(begin(happiness), end(happiness), greater<int>());

//         long long result = 0;  

//         int count = 0;  

        
//         for (int i = 0; i < k; i++) {
//             result += max(happiness[i] - count, 0);

//             count++;
//         }

//         return result; 
//     }
// };


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result = 0;   
        int count = 0;          

        priority_queue<int> pq; 

        // Traditional for loop to insert all elements into the max-heap
        for (int i = 0; i < happiness.size(); i++) {
            pq.push(happiness[i]);  
        }

        for (int i = 0; i < k; i++) {
            int hap = pq.top();    
            pq.pop();               

            result += max(hap - count, 0);

            count++;               
        }

        return result;  
    }
};
