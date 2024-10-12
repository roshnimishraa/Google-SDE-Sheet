### Approach 1: Recursion

class Solution{
    int solve(int i,int j,int arr[], int n)
    {
        if(i==j){
            return 0;
        }
        int mini = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps = (arr[i-1]*arr[k]*arr[j])+ solve(i,k,arr,n)+
        solve(k+1,j,arr,n);
        mini = min(mini,steps);
    }
    return mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
       return solve(1,N-1, arr,N);
    }
};


### Approach 2: Memoization

class Solution{
    int solve(int i,int j,int arr[], int n,vector<vector<int>> &dp)
    {
        if(i==j){
            return 0;
        }
        if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
        int mini = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps = (arr[i-1]*arr[k]*arr[j])+ solve(i,k,arr,n,dp)+
        solve(k+1,j,arr,n,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(Nr,dp);
    }
};

### Approach 3: Tabulation

class Solution{
    int solve(int n, int arr[])
    {
          vector<vector<int>> dp(n+1, vector<int> (n+1,0));
       
for(int i=1;i<n;i++){
    dp[i][i] = 0;
}
for(int i=n-1;i>=1;i--){
    for(int j=i+1;j<n;j++)
    {
         int mini = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps = (arr[i-1]*arr[k]*arr[j])+ dp[i][k]+ dp[k+1][j];
    
        mini = min(mini,steps);
    }
     dp[i][j] = mini; 
    }
}
 return dp[1][n-1];     
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
      
       return solve(N, arr);
    }
};
