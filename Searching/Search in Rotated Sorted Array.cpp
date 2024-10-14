### Approach 1: Linear Search

# Time Complexity: O(N)
# Space Complexity: O(1) 

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
};

### Approach 2: Binary Search

# Time Complexity: O(log N)
# Space Complexity: O(1)

class Solution {
  public:
    int search(vector<int>& arr, int key) {
      int n=arr.size();
      int low=0, high=n-1;
      while(low <= high){
          int mid = low+(high-low)/2;
          if(arr[mid] == key) return mid;
          
          if(arr[low] <= arr[mid])
          {
              if(arr[low] <= key && key <= arr[mid])
              {
                  high = mid-1;
              }
              else{
                  low = mid+1;
              }
          }
          
          else{
              if(arr[mid] <= key && key <= arr[high])
              {
                  low = mid+1;
              }
              else{
                  high = mid-1;
              }
          }
      }
      return -1;
    }
};
