### Approach 1: Brute Force (Two-Nested Loops)

# Time Complexity: O(N^2) 
# Space Complexity: O(1)

class Solution {
  public:
   
    vector<int> subarraySum(vector<int> arr, int n, long long s) 
    {

    for(int i=0;i<n;i++){
                int sum=0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum == s){
                return {i+1,j+1};
            }
        }
    }
    return {-1};
    }
};

### Approach 2: Sliding Window

# Time Complexity: O(N)
# Space Complexity: O(1)

class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        int start=0, end=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr += arr[i];
            
            if(curr >= s)
            {
                end=i;
                while(curr > s && start < end)
                {
                    curr -= arr[start];
                    start++;
                }
                if(curr == s){
                    return {start+1, end+1};
                }
            }
        }
        return {-1};
    }
};
