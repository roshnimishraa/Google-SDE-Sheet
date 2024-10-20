class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int n = arr.size();
    int plat_needed = 1,ans=1;
    int i = 1,j=0;
    while(i< n && j<n)
    {
        if(arr[i] <= dep[j])
        {
            plat_needed++;
            i++;
        }
        else if(arr[i] > dep[j])
        {
            plat_needed--;
            j++;
            
        }
        if(plat_needed > ans){
            ans = plat_needed;
        }
    }
    return ans;
    }
};
