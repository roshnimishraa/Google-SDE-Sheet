### Approach 1: Brute Force

Time Complexity: O(n^2), Trying all subarrays from every index, used nested loop for the same
Auxiliary Space: O(1)

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
          int n = arr.size();
          vector<int> ans;
          bool flag = false;
          for(int i=0;i<n;i++)
          {
              int currSum = arr[i];
              if(currSum == target)
              {
                  ans.push_back(i+1);
                  ans.push_back(i+1);
                  flag = true;
                  break;
              }
              else{
                  for(int j=i+1; j<n; j++)
                  {
                      currSum += arr[j];
                      if(currSum == target)
                      {
                          ans.push_back(i+1);
                          ans.push_back(j+1);
                          flag = true;
                          break;
                      }
                  }
                  if(flag) break;
              }
          }
          if(flag){
              return ans;
          }
          return {-1};
    }
};

### Approach 2: Expected 

Time Complexity: O(n)
Auxiliary Space: O(1). Since no extra space has been taken.
  
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
      if(target == 0) {
          return {-1};
      }
      int n = arr.size();
     int start = 0, end = 0;
     long long windowSum = arr[0];
     while(end < n)
     {
         if(windowSum < target)
         {
             end++;
             windowSum += arr[end];
         }
         else if(windowSum == target)
         {
             return {start+1,end+1};
         }
         else if(windowSum > target)
         {
             windowSum -= arr[start];
             start++;
         }
     }
     return {-1};
    }
};
