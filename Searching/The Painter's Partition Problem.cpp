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

# Time Complexity: O(N * log(sum(arr[])-max(arr[])+1))
# Space Complexity:  O(1)

class Solution
{
  public:
 
int solve(int arr[],int n, int time,int k) {
    
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + arr[i] <= time) {
            //allocate board to current painter
            boardsPainter += arr[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = arr[i];
        }
    }
    return (painters <= k) ? 1 : 0 ;
}

    
  public:
    long long minTime(int arr[], int n, int k)
    {
         long long sum=0;
         int ans=-1;
        for (int i=0;i<n;i++){
          sum += arr[i];
        }
        
        long long low=*max_element(arr,arr+n);
        long long high = sum;
         
        while (low<=high)
        {
             long long mid=low+(high-low)/2;
        if(solve(arr,n,mid,k) == 1)
        {
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        }
        return ans;
    }
};
