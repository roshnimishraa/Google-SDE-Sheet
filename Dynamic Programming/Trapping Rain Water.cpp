### Approach 1: Brute Force 

# Time Complexity: O(NXN)
# Space Complexity: O(1)

class Solution {
  public:
    long long trappingWater(vector<int> &arr) {
        int n=arr.size();
      int waterTrapped=0;
      for(int i=0;i<n;i++)
      {
         int j=i;
         int leftMax=0, rightMax=0;
         while(j>=0)
         {
             leftMax = max(leftMax,arr[j]);
             j--;
         }
         j=i;
         while(j<n)
         {
             rightMax = max(rightMax, arr[j]);
             j++;
         }
         waterTrapped += min(leftMax,rightMax) - arr[i];
      }
      return waterTrapped;
    }
};

### Approach 2: Better Solution

Time Complexity: O(3*N) as we are traversing through the array only once. And O(2*N) for computing prefix and suffix array.
Space Complexity: O(N)+O(N) for prefix and suffix arrays.

class Solution {
public:
    int trap(vector<int>& height) {
     int n = height.size();
     int prefix[n], suffix[n];
     prefix[0] = height[0];
     for(int i=1;i<n;i++)
     {
        prefix[i] = max(prefix[i-1], height[i]);
     }   
    
     suffix[n-1] = height[n-1];
     for(int i=n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1],height[i]);
     }
     int waterTrapped =0;
     for(int i=0;i<n;i++)
     {
        waterTrapped += min(prefix[i],suffix[i])-height[i];
     }
     return waterTrapped;
    }
};

### Approach 3: Optimal Solution (Two Pointer)

Time Complexity: O(N) because we are using 2 pointer approach.
Space Complexity: O(1) because we are not using anything extra.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left=0, right=n-1;
        int res=0;
        int maxLeft=0, maxRight=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
              if(height[left] >= maxLeft)
              {
                maxLeft= height[left];
              }
              else{
                res += maxLeft-height[left];
              }
           left++;
            }
            else{
           if(height[right] >= maxRight){
               maxRight = height[right];
           }
           else{
              res += maxRight - height[right];
           }
           right--;
            }
        }
        return res;
    }
};
  
