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
