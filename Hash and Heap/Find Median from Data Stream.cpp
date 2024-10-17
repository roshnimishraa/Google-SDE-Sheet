Time Complexity: O(n * log n), All the operations within the loop (push, pop) take O(log n) time in the worst case for a heap of size N.
Auxiliary Space: O(n)

class MedianFinder {
public:
priority_queue<int> leftMaxHeap;
priority_queue<int,vector<int>,greater<int>> rightMinHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty() && rightMinHeap.empty()){
            leftMaxHeap.push(num);
        }
        else{
            if(leftMaxHeap.top() < num)
            {
                rightMinHeap.push(num);
            }
            else{
                leftMaxHeap.push(num);
            }
        }
        int n = leftMaxHeap.size();
        int m = rightMinHeap.size();

        // check heap is balanced or not(heapify)
    if(n-m == 2 || n-m == 2)
    {
        if(n>m){
            int element = leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(element);
        }
        else{
            int element = rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(element);
        }
    }
    }
    
    double findMedian() {
    int n = leftMaxHeap.size();
    int m = rightMinHeap.size();

    // if n + m is even 
    if((n+m)%2 == 0)
    {
        return ((double)(leftMaxHeap.top() + (double)rightMinHeap.top()))/2.0;
    }        
    if(n > m){
        return leftMaxHeap.top();
    }

    return rightMinHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
