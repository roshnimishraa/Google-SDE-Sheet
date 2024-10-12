### Approach 1: Recursion 

class Solution{
    private:
    int solve(int index, int maxWeight, int val[], int wt[])
    {
        // base condition
        if(index == 0){
         if(maxWeight >= wt[0])
         {
             return (maxWeight/wt[0])*val[0];
         }
         else{
             return 0;
         }
        }
// not take 
int notTake = solve(index-1, maxWeight, val,wt);
int take=0;
if(maxWeight >= wt[index])
{
    take = val[index] + solve(index, maxWeight-wt[index], val,wt);
}
return max(take, notTake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
     return solve(N-1, W, val, wt);
    }
};

### Approach 2: Memoization 

class Solution{
    private:
    int solve(int index, int maxWeight, int val[], int wt[],
    vector<vector<int>> &dp)
    {
        // base condition
        if(index == 0){
         if(maxWeight >= wt[0])
         {
             return (maxWeight/wt[0])*val[0];
         }
         else{
             return 0;
         }
        }
        if(dp[index][maxWeight] != -1) {
            return dp[index][maxWeight];
        }
// not take 
int notTake = solve(index-1, maxWeight, val,wt,dp);
int take=0;
if(maxWeight >= wt[index])
{
    take = val[index] + solve(index, maxWeight-wt[index], val,wt,dp);
}
return dp[index][maxWeight] = max(take, notTake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1,vector<int> (W+1,-1));
     return solve(N-1, W, val, wt,dp);
    }
};


### Approach 3: Tabulation


class Solution{
  private:
    
int solve(int n, int maxWeight, int val[], int wt[])
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1, 0));
    
    //base case
    for(int W=wt[0]; W<=maxWeight; W++)
    {
      dp[0][W] = (W/wt[0])*val[0];
    }
    
    for(int index=1;index<n;index++)
    {
        for(int W=0;W<=maxWeight; W++)
        {
            int notTake = dp[index-1][W];
        int take = INT_MIN;
    if(wt[index] <= W)
    {
        take = val[index] + dp[index][W-wt[index]];
    }
    dp[index][W] = max(take,notTake);
        }
    }
    return dp[n-1][maxWeight];
}
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
      
      return solve(N,W, val,wt); 
      }
};
