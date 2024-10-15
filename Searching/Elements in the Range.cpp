class Solution {
  public:
    bool check_elements(int arr[], int n, int A, int B) {
      set<int> s;
      for(int i=0;i<n;i++)
      {
          if(arr[i] >= A && arr[i]<=B){
              s.insert(arr[i]);
          }
          
      }
      if(s.size() == abs(B-A)+1)
          return true;
          
         return false;
    }
};
