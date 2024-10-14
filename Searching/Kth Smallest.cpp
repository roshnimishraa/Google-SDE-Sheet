### Approach : Max-Heap (Priority Queue) 

# Time Complexity: O(N) * log(K)
# Space Complexity: O(k)

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
            if(pq.size() > k)
        {
            pq.pop();
        }
        }
        
        return pq.top();
    }
};
