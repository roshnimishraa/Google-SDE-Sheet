### Approach 1: Recursion

class Solution {
    private:
    int solve(int index, string &s)
    {
        if(index == s.length()){
            return 1;
        }
    // leading zero
    if(s[index] == '0')
    {
        return 0;
    }
    int op1 = solve(index+1,s);
    int op2=0;
    if(index+1 < s.length()){
        if(s[index] == '1' || s[index] == '2' && s[index+1] <='6')
        {
            op2 = solve(index+2,s);
        }
    }
    return op1+op2;
    }
public:
    int numDecodings(string s) {
        return solve(0,s);
    }
};

### Approach 2: Memoization 

class Solution {
    private:
    int solve(int index, string &s,vector<int> &dp)
    {
        if(index == s.length()){
            return 1;
        }
    // leading zero
    if(s[index] == '0')
    {
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int op1 = solve(index+1,s,dp);
    int op2=0;
    if(index+1 < s.length()){
        if(s[index] == '1' || s[index] == '2' && s[index+1] <='6')
        {
            op2 = solve(index+2,s,dp);
        }
    }
    return dp[index] = op1+op2;
    }
public:
    int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n+1,-1);
        return solve(0,s,dp);
    }
};

### Approach 3: Tabulation

class Solution {
    private:
    int solve(string &s)
    {
           int n = s.length();
    vector<int> dp(n+1,0);
     dp[n] = 1;
    // leading zero
   for(int i=n-1;i>=0;i--){
    if(s[i] == '0')
    {
        dp[i] = 0;
    }
    else{
        int op1 = dp[i+1];
  int op2=0;
    if(i+1 < s.length()){
        if(s[i] == '1' || s[i] == '2' && s[i+1] <='6')
        {
            op2 = dp[i+2];
        }
    }
    dp[i] = op1+op2;
    }
   }
   
 return dp[0];
    }
public:
    int numDecodings(string s) {
    return solve(s);
    }
};
