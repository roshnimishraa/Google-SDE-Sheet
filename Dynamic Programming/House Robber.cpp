### Approach 1: Recursion

class Solution {
    int solve(int index,vector<int> &nums)
    {
        // base case
   if(index<0){
    return 0;
   }
        // not take
    int notTake = solve(index-1, nums);
    int take=0;
 take = nums[index] + solve(index-2,nums);
   
    return max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        return solve(n-1,nums);
    }
};

### Approach 2: Memoization

# Time Complexity: O(N)
Reason: The overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. 
Hence total time complexity is O(N).
# Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)

class Solution {
    int solve(int index,vector<int> &nums, vector<int> &dp)
    {
        // base case
   if(index<0){
    return 0;
   }
   if(dp[index] != -1){
    return dp[index];
   }
        // not take
    int notTake = solve(index-1, nums,dp);
    int take=0;
 take = nums[index] + solve(index-2,nums,dp);
   
    return dp[index] = max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
};

### Approach 3: Tabulation

# Time Complexity: O(N)
Reason: We are running a simple iterative loop
# Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
  
class Solution {
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n+1,0);

        // base case
       dp[0] = nums[0];

 for(int index=1;index<n;index++)
 {
     int take = nums[index];
 if(index > 1){
take += dp[index-2];
 } 
  int notTake =0+ dp[index-1];
    
    dp[index] = max(take,notTake); 
 }
  
  return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        
        return solve(nums);
    }
};

### Approach 4: Space Optimization

# Time Complexity: O(N)
Reason: We are running a simple iterative loop
# Space Complexity: O(1)
Reason: We are not using any extra space.
  
class Solution {
    int solve(vector<int> &nums)
    {
        int n = nums.size();
       int prev=0, prev2=0;

        // base case
      prev = nums[0];

 for(int index=1;index<n;index++)
 {
     int take = nums[index];
 if(index > 1){
take += prev2;
 } 
  int notTake =0+ prev;
    
   int curr = max(take,notTake); 
    prev2=prev;
    prev = curr;
 }
  
  return prev;
    }
public:
    int rob(vector<int>& nums) {
        
        return solve(nums);
    }
};
