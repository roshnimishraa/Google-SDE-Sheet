### Approach 1: Naive (Nested Loops)

Time complexity: O(N3). 
Three nested loops are traversing in the array, so time complexity is O(n^3).
Space Complexity: O(1). 

class Solution{
    public:
    int closest3Sum(int arr[], int n, int tar)
    {
       int ans = INT_MAX;
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               for(int k=j+1;k<n;k++)
               {
                  if(abs(tar - ans) > abs(tar - (arr[i] + arr[j] + arr[k])))
                  {
                      ans = (arr[i]+arr[j]+arr[k]);
                  }
               }
           }
       }
       return ans;
    }
};

### Approach 2: Two Pointer

Time complexity: O(N2). 
There are only two nested loops traversing the array, so time complexity is O(n^2). Two pointer algorithm take O(n) time and the first element can be fixed using another nested traversal.
Space Complexity: O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
int ans = 1e9;
        for(int i=0;i<n-2;i++)
        {
  int j = i+1;
  int k=n-1;
  while(j<k)
  {
    int sum = nums[i] + nums[j] + nums[k];

    if(sum == target)
    return sum;

    if(abs(target-sum) < abs(target-ans))
    ans = sum;

    if(sum > target)
    k--;
    else 
    j++;
  }
        }
        return ans;
    }
};
