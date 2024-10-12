### Approach 1: Recursion

class Solution {
    bool solve(int i,int j, string s, string p)
    {
        // base case
    if(i<0 && j<0) return true;
    
    if(i<0 && j>=0) return false;

    if(i>=0 && j<0)
    {
        for(int k=0;k<=i;k++)
        {
            if(p[k] != '*')
            {
                return false;
            }
        }
        return true;
    }
        if(s[j] == p[i] || p[i] == '?')
        {
            return solve(i-1,j-1,s,p);
        }
    else if(p[i] == '*')
    {
        // empty || shrink string
        return solve(i-1,j,s,p) || solve(i,j-1,s,p);
    }
    return false;
    }
public:
    bool isMatch(string s, string p) {
      int n = p.length();
      int m = s.length();
      return solve(n-1, m-1, s,p);   
    }
};

### Approach 2: Memoization

class Solution {
    private:
  bool solve(int i,int j,string &s, string &p,vector<vector<int>> &dp)
  {
    if(i < 0 && j<0) return true;
    if (i < 0 && j >= 0)
        return false;
    if(i>=0 && j<0) 
    {
        for(int k=0; k<=i; k++)
        {
            if(p[k] != '*'){
            return false;
            }
        }
        return true;
    }
if(dp[i][j] != -1){
    return dp[i][j];
}
    // match
    if(p[i] == s[j] || p[i] == '?')
    {
        return dp[i][j] = solve(i-1, j-1, s, p,dp);
    }
    else if(p[i] == '*')
    {
        // empty || matches 
return dp[i][j]= solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
    }
    return dp[i][j] = false;
  }
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(n-1,m-1,s,p,dp);
    }
};

### Approach 3: Tabulation (Top-Down)

class Solution {
    private:
  bool solve(string &s, string &p)
  {
      int n = p.length();
        int m = s.length();
    vector<vector<bool>> dp(n+1,vector<bool> (m+1,0));
   dp[0][0] = true;
   
  for(int j=1;j<=m;j++)
  {
    dp[0][j] = false;
  }

   for(int i=1;i<=n;i++)
   {
    bool flag = true;
    for(int k=1;k<=i;k++)
    {
        if(p[k-1] !='*')
        {
        flag = false;
        break;
        }
    }
    dp[i][0] = flag;
   }
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=m;j++)
    {
    // match
    if(p[i-1] == s[j-1] || p[i-1] == '?')
    {
         dp[i][j] =dp[i-1][j-1];
    }
    else if(p[i-1] == '*')
    {
        // empty || matches 
 dp[i][j]=dp[i-1][j] || dp[i][j-1];
    }
    else {
        dp[i][j] = false;
    }
    }
   }
return dp[n][m];
  }
public:
    bool isMatch(string s, string p) {
      
        return solve(s,p);
    }
};

### Approach 4: Space Optimization

class Solution {
    private:
  bool solve(string s, string p)
  {
     int n = p.length();
    int m = s.length();
vector<bool> prev(m+1,false);
vector<bool> curr(m+1,false);

// case 1
prev[0] = true;
// case 2
for(int j=1;j<=m;j++){
 prev[j] = false;
 }
for(int i=1;i<=n;i++)
{
    bool flag = true;
     for(int k=1; k<=i; k++)
        {
            if(p[k-1] != '*'){
                flag = false;
                break;
            }
        }
      curr[0] = flag;
}
 
for(int i=1;i<=n;i++){
	        // case 3
            bool flag = true;
            for(int k=1;k<=i;k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
    for(int j=1;j<=m;j++)
    {
 // match
    if(p[i-1] == s[j-1] || p[i-1] == '?')
    {
         curr[j] = prev[j-1];
    }
    else if(p[i-1] == '*')
    {
        // empty || matches 
curr[j]= prev[j] || curr[j-1];
    }
    else
    curr[j] = false;
    }
    prev = curr;
}
   return prev[m];
  }
public:
    bool isMatch(string s, string p) {      
 return solve(s,p);
    }
};
