class MedianFinder {
public:
    // max-heap to store the smaller half of numbers
    priority_queue<int> left_max_heap; 
    
    // min-heap to store the larger half of numbers
    priority_queue<int, vector<int>, greater<int>> right_min_heap; 
    
    // constructor initializes the MedianFinder object
    MedianFinder() {
        
    }
    
    // function to add a number into the data structure
    void addNum(int num) {
        // if left_max_heap is empty OR number is smaller than the largest element of left_max_heap
        // then insert into left_max_heap (smaller half)
        if(left_max_heap.empty() || num < left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            // otherwise, it belongs to the larger half -> insert into right_min_heap
            right_min_heap.push(num);
        }
        
        
        // Now balance the two heaps so that:
        // 1. left_max_heap has either equal elements as right_min_heap
        // 2. OR left_max_heap has only one extra element
        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {
            // too many elements in left heap -> move the top element to right heap
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if(left_max_heap.size() < right_min_heap.size()) {
            // if right heap has more elements -> move its top element to left heap
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    // function to return the median of all elements added so far
    double findMedian() {
        // if both heaps have equal size -> median is the average of two middle elements
        if(left_max_heap.size() == right_min_heap.size()) {
            return (double)(left_max_heap.top() + right_min_heap.top()) / 2;
        }
        
        // if odd number of elements -> left_max_heap will always have one extra element
        return left_max_heap.top();
    }
};
