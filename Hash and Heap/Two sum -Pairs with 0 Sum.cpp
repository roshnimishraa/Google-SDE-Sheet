# Time Complexity: O(N Log N)
# Space Complexity: O(N)

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
      set<vector<int>> ans;
      sort(arr.begin(), arr.end());
      int n = arr.size();
      int i=0, j=n-1;
    //   two-pointer
      while(i<j)
      {
          int sum = arr[i]+arr[j];
          if(sum == 0){
              ans.insert({arr[i],arr[j]});
              i++;
              j--;
          }
          else if(sum < 0){
              i++;
          }
          else{
              j--;
          }
      }
      vector<vector<int>> res(ans.begin(),ans.end());
      return res;
    }
};
