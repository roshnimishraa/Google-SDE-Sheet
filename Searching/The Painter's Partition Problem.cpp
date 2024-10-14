### Approach 1: Brute Force 

# Time Complexity: O(N * (sum(arr[])-max(arr[])+1))
# Space Complexity:  O(1) 

class Solution
{
  public:
  long long countPainters(int arr[], int n,int time)
  {
      int painters = 1;
      long long boardPainters = 0;
      for(int i =0;i<n;i++)
      {
          if(arr[i] + boardPainters <= time)
          {
              boardPainters += arr[i];
          }
          else{
              painters++;
              boardPainters = arr[i];
          }
      }
      return painters;
  }
    long long minTime(int arr[], int n, int k)
    {
    int low = *max_element(arr, arr+n);
    int high = accumulate(arr, arr+n, 0);
    for(int time=low; time<=high; time++)
    {
        if(countPainters(arr, n, time) <= k)
        {
            return time;
        }
    }
    return low;
    }
};

### Approach 2: Binary Search

