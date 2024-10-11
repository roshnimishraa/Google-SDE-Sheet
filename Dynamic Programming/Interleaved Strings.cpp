### Approach 1: Recursion 

# Time Complexity: Exponential
# Space Complexity: O(n)

class Solution {
    private:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3)
    {
            int n1=s1.length();
        int n2=s2.length();
        int n=s3.length();
        // base case
        if(i==n1 && j==n2 && k==n){
            return true;
        }
        if(k>=n){
            return false;
        }
        bool result = false;
    if(s1[i] == s3[k])
    {
        result= solve(i+1,j,k+1,s1,s2,s3);
    }
    if(result == true){
        return true;
    }
    if(s2[j] == s3[k])
    {
     result = solve(i,j+1,k+1,s1,s2,s3);
    }
return result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n=s3.length();
        return solve(0,0,0,s1,s2,s3);
    }
};

### Approach 2: Memoization (3-Variables) 

# Time Complexity: O(n1) * O(n2) * O(n)
# Space Complexity: O(n1*n2*n) + O(n)
class Solution {
    private:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3,  vector<vector<vector<int>>> &dp)
    {
            int n1=s1.length();
        int n2=s2.length();
        int n=s3.length();
        // base case
        if(i==n1 && j==n2 && k==n){
            return true;
        }
        if(k>=n){
            return false;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        bool result = false;
    if(s1[i] == s3[k])
    {
        result= solve(i+1,j,k+1,s1,s2,s3,dp);
    }
    if(result == true){
        return dp[i][j][k]=result;
    }
    if(s2[j] == s3[k])
    {
     result = solve(i,j+1,k+1,s1,s2,s3,dp);
    }
return dp[i][j][k] = result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n=s3.length();
    vector<vector<vector<int>>> dp(n1+1,vector<vector<int>> (n2+1, vector<int> (n+1,-1)));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};

### Approach 2: Memoization (2 Variables)

class Solution {
    private:
    bool solve(int i, int j,string &s1, string &s2, string &s3,  vector<vector<int>> &dp)
    {
            int n1=s1.length();
        int n2=s2.length();
        int n=s3.length();
    //k = i+j
        // base case
        if(i==n1 && j==n2 && i+j==n){
            return true;
        }
        if(i+j >=n){
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool result = false;
    if(s1[i] == s3[i+j])
    {
        result= solve(i+1,j,s1,s2,s3,dp);
    }
    if(result == true){
        return dp[i][j]=result;
    }
    if(s2[j] == s3[i+j])
    {
     result = solve(i,j+1,s1,s2,s3,dp);
    }
return dp[i][j] = result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
     
vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};

### Approach 3: Tabulation (Bottom-Up)

class Solution {
    private:
    bool solve(string &s1, string &s2, string &s3)
    {
         int n=s1.length();
        int m=s2.length();
     
vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
   
   if(n+m != s3.size()){
    return false;
   }
for(int i=n; i>=0; i--){
    for(int j=m;j>=0;j--)
    {
        int k=i+j;
     if(i==n && j==m && k==s3.size()){
        dp[i][j] = true;
     }

 else{
     bool result = false;
    if(i<n && s1[i] == s3[k])
    {
        result= dp[i+1][j];
    }
   
    if(j<m && s2[j] == s3[k])
    {
     result = result || dp[i][j+1];
    }
    dp[i][j] = result;
 }
    }
}

       
return dp[0][0];

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        return solve(s1,s2,s3);
    }
};


### Approach 4: Space Optimization

class Solution {
    private:
    bool solve(string &s1, string &s2, string &s3)
    {
         int n=s1.length();
        int m=s2.length();
     
vector<bool> next(m+1,false);
vector<bool> curr(m+1,false);

   if(n+m != s3.size()){
    return false;
   }
for(int i=n; i>=0; i--){
    for(int j=m;j>=0;j--)
    {
        int k=i+j;
     if(i==n && j==m && k==s3.size()){
       curr[j] = true;
     }

 else{
     bool result = false;
    if(i<n && s1[i] == s3[k])
    {
        result= next[j];
    }
   
    if(j<m && s2[j] == s3[k])
    {
     result = result || curr[j+1];
    }
   curr[j] = result;
 }
 next = curr;
    }
}

       
return next[0];

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        return solve(s1,s2,s3);
    }
};

