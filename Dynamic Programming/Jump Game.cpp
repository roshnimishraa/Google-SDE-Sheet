### Approach 1: Recursion 

# Time Complexity : O(nn). There are nn (upper bound) ways of jumping from the first position to the last, where n is the length of the array.
# Space Complexity :  Space complexity O(n). Recursion requires additional memory for the stack frames.
  
class Solution {
    private:
bool solve(int index, vector<int> &nums)
{
    int n = nums.size();
    if(index == n-1) return true;
   int reachable = index + nums[index];
for(int k=index+1; k<=reachable; k++)
{
    if(solve(k, nums)){
        return true;
    }
}
 return false;
}
public:
    bool canJump(vector<int>& nums) {
        return solve(0, nums);      
    }
};

### Approach 2: Memoization

class Solution {
    private:
bool solve(int index, vector<int> &nums,vector<int> &dp)
{
    int n = nums.size();
    if(index == n-1) return true;
   int reachable = index + nums[index];
   if(dp[index] != -1){
    return dp[index];
   }
for(int k=index+1; k<=reachable; k++)
{
    if(solve(k, nums,dp)){
        return dp[index] = true;
    }
}
 return dp[index] = false;
}
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
    vector<int> dp(n, -1);
        return solve(0, nums,dp);      
    }
};

### Approach 3: Tabulation

class Solution {
    private:
    bool solve(vector<int> &nums){
        int n= nums.size();
    vector<bool> dp(n,0);
dp[n-1] = true;
for(int i=n-2;i>=0;i--)
{
    int possible = false;
    for(int jumps = nums[i]; jumps>=1; jumps--)
    {
        int reachable = i + jumps;
        if(reachable > n-1) continue;
        possible = possible || dp[reachable];
    }
    dp[i] = possible;
}
    return dp[0];
    }
public:
    bool canJump(vector<int>& nums) {
        return solve(nums);
    }
};
