### Approach 1: Brute Force 

Time Complexity : O(n^2)
Auxiliary Space: O(1)
  
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
         int count=0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum += arr[j];
                if(sum == k)
                count++;
            }
        }
        return count;
    }
};

### Approach 2: 
