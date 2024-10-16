### Approach 1: Brute Force (Nested Loops)

Time Complexity: O(n * k)
Auxiliary Space: O(1)

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
         for(int i=0;i<=n-k;i++)
         {
             int maxi = arr[i];
             for(int j=1;j<k;j++)
             {
                 if(arr[i+j] > maxi)
                 {
                     maxi = arr[i+j];
                 }
             }
             ans.push_back(maxi);
         }
         return ans;
    }
};

### Approach 2: Max-Heap 

Time Complexity: O(n log n), Where n is the size of the array.
Auxiliary Space: O(n), where n is the size of the array, this method requires O(n) space in the worst case when the input array is an increasing array

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        // element, index
  priority_queue<pair<int,int>> pq;
  for(int i=0;i<k;i++)
  {
      pq.push({arr[i],i});
  }
  ans.push_back(pq.top().first);
  
    // Process the remaining elements
    for(int i=k;i<n;i++)
    {
        pq.push({arr[i],i});
 // Remove elements that are outside the current window
        while(pq.top().second <= i-k)
        pq.pop();
        
        
        ans.push_back(pq.top().first);
    }
    return ans;
    }
};
