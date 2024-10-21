### Approach 1: Brute Force

Time Complexity: O(n log n + 2^n). Since there are 2^n possible subsets of an array of size n. Also Sorting the input array takes O(n log n) time , Hence  O(n log n + 2^n).
Space Complexity: O(n) due to the sorting step and the recursive stack.

class Solution {
    private:
    int solve(vector<int> a, int l, int r, int &ans, int m)
    {
        if(l >= r) return INT_MAX;
        if(r - l + 1 < m) return INT_MAX;
        ans = min(ans, a[r] - a[l]);
        solve(a, l+1, r, ans, m);
        solve(a, l, r-1, ans, m);
        return a[r] - a[l];
    }
    
  public:
    int findMinDiff(vector<int> arr, int m) {
       int ans = LONG_MAX;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        ans = arr[n-1] - arr[0];
        solve(arr, 0, n-1, ans, m);
        return ans;
    }
};

### Approach 2: Optimial 

Time Complexity:  O(n log n) due to the sorting operation.
Space Complexity: O(1), It does not use any additional data structures .
  
class Solution {
  public:
    int findMinDiff(vector<int> arr, int m) {
       sort(arr.begin(), arr.end());
       int start = 0, end=0;
       int mind = INT_MAX;
       
       for(int i=0; i+m-1 < arr.size(); i++)
       {
           int diff = arr[i+m-1] - arr[i];
           if(mind > diff){
               mind = diff;
               start = i;
               end = i+m-1;
           }
       }
       return arr[end] - arr[start];
    }
};
