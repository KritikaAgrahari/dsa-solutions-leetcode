class KthLargest {
public:
    // Min-heap to keep track of K largest elements
    // The root (top) of this min-heap will always store the Kth largest element
    priority_queue<int, vector<int>, greater<int>> pq;  
    int K; // store value of k
    
    // constructor: initializes K and processes the initial nums array
    KthLargest(int k, vector<int>& nums) {
        K = k;
        
        // loop through each element of nums
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);  // push current element into min-heap
            
            // if heap size exceeds k, remove the smallest element
            // this ensures heap only keeps track of k largest elements
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    // function to add a new element into the stream
    int add(int val) {
        pq.push(val); // insert new element into min-heap
        
        // again, if heap size exceeds K, remove the smallest element
        if(pq.size() > K)
            pq.pop();
        
        // top of heap now represents the Kth largest element
        return pq.top();
    }
};
