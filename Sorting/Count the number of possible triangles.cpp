### Approach 1: Brute Force (Nested Loops)

Time Complexity: O(N^3) where N is the size of input array.
Space Complexity: O(1)
  
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
  int count=0;
  for(int i=0;i<n;i++)
  {
      for(int j=i+1;j<n;j++)
      {
          for(int k=j+1;k<n;k++)
          {
              if(arr[i]+arr[j] > arr[k] && 
              arr[i]+arr[k] > arr[j] && 
              arr[k] + arr[j] > arr[i])
              count++;
          }
      }
  }
  return count;
    }
};

### Approach 2: Optimized (Two Pointer)

Time complexity: O(n^2). 
As two nested loops are used, but overall iterations in comparison to the above method reduces greatly.
Space Complexity: O(1). 
As no extra space is required, so space complexity is constant

class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
    int count=0;
    sort(arr, arr+n);
    for(int i=n-1;i>=1;i--)
    {
        int l=0, r=i-1;
        while(l < r)
        {
            if(arr[l] + arr[r] > arr[i])
            {
                count += r - l;
                r--;
            }
            else{
                l++;
            }
        }
    }
    return count;
    }
};
