class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max-heap to always get the two heaviest stones first
        priority_queue<int> pq; 
        
        // Insert all stones into the heap
        for(int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);  
        }
        
        // Keep smashing the two heaviest stones until <= 1 stone remains
        while(pq.size() > 1) {
            int a = pq.top(); // get heaviest stone
            pq.pop();         // remove it
            
            int b = pq.top(); // get second heaviest stone
            pq.pop();         // remove it
            
            // If stones are unequal, push the difference back (new stone formed)
            if(a != b)
                pq.push(abs(a - b));
        }
        
        // If there is a stone left, return its weight; otherwise return 0
        if(pq.size())
            return pq.top();
        return 0;
    }
};
