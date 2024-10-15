### Approach 1: Brute Force 

Time Complexity: O(max(a[]) * N)
Space Complexity: O(1) 
  
class Solution {
    private:
    int calculateTotalHours(vector<int> &arr, int hour)
    {
        int totalH = 0;
        int n =arr.size();
        for(int i=0;i<n;i++){
            totalH += ceil((double)(arr[i]) / (double)(hour));
        }
        return totalH;
    }
  public:
    int KoKoEat(vector<int>& arr, int k) {
        int maxi= INT_MIN;
        int n =arr.size();
        for(int i=0;i<n;i++){
            maxi = max(arr[i],maxi);
        }

for(int i=1;i<=maxi;i++){
    int reqTime = calculateTotalHours(arr,i);
    if(reqTime <= k){
        return i;
    }
}
return -1;
    }
};

### Approach 2: Optimal (Binary Search) 

Time Complexity: O(N * log(max(a[])))
Space Complexity: O(1) as we are not using any extra space to solve this problem.

class Solution {
    private:
    int calculateTotalHours(vector<int> &arr, int hour)
    {
        int totalH = 0;
        int n =arr.size();
        for(int i=0;i<n;i++){
            totalH += ceil((double)(arr[i]) / (double)(hour));
        }
        return totalH;
    }
  public:
    int KoKoEat(vector<int>& arr, int k) {
        int maxi= INT_MIN;
        int n =arr.size();
        for(int i=0;i<n;i++){
            maxi = max(arr[i],maxi);
        }

    int low=1, high = maxi;
    while(low <= high){
        int mid = low + (high-low)/2;
        
    int totalH = calculateTotalHours(arr,mid);
    if(totalH <= k){
        high = mid-1;
    }
    else{
        low = mid+1;
    }
    }
return low;
    }
};
