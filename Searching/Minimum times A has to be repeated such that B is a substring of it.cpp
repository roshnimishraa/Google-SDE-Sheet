### Approach 1: Brute Force

# Time complexity : O(N.M)
# Space complexity : O(M) (temporary string)

class Solution {
    private:
    bool check(string &a, string &b)
    {
        int m = a.size();
        int n =b.size();

        for(int i=0;i<=m-n;i++)
        {
            int j;
   for( j=0;j<n;j++)
   {
    if(a[i+j] != b[j])
    break;
   }
   if(j == n){
    return true;
   }
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.size();
        int n = b.size();
        int ans=1;
        string tmp = a;
        while(a.size() < b.size()){
            a += tmp;
            ans++;
        }
        if(check(a,b)){
            return ans;
        }
         a += tmp;
         if(check(a,b)){
            return ans+1;
         }
         return -1;
    }
};

### Approach 2: Rabin-Karp Algorithm : It is used to find given substring pattern in given text. It is also known as string matching algorithm.

# Time complexity : O(M+N)
# Space complexity : O(2*M) ~ O(M) (prefix hash array and power array of size M)

class Solution {
    public:
  int Rabin_Karp(string s1, string s2)
  {
    long long m = s1.size();
    long long n = s2.size();

    long long p = 31;
    long long pow = 1;
    long long mod = 1e9+7;
    long long targetHashVal = 0;
    // targetHashVal - calculate hash value of pattern
    for(long long i=0;i<n;i++)
    {
targetHashVal = (targetHashVal + (s2[i]-'a'+1)*pow)%mod;
pow = (pow * p) % mod;
    }
    // Rabin-Karp algo
    // prefix hash array
    vector<long long> pha(m);
    vector<long long> pa(m);

    pha[0] = s1[0]-'a'+1;
    pa[0] = 1;
    pow = p;
    for(long long i=1;i<m;i++)
    {
        pha[i] = (pha[i-1] + (s1[i]-'a'+1)*pow)%mod;
        pa[i] = pow;
        pow = (pow*p)%mod;
    }
    long long sp=0, ep=n-1;
    while(ep < m)
    {
        long long win = pha[ep];
    if(sp > 0)
    win = (win-pha[sp-1] + mod)%mod;

    if(win == (targetHashVal * pa[sp])%mod)
    {
        return 1;
    }
    sp++;
    ep++;
    }
    return 0;
  }
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int count=1;
        string source=a;
        while(source.size() < b.size()){
            source += a;
            count++;
        }
        // edge cases
        if(source == b){
            return count;
        }
        if(Rabin_Karp(source, b) == 1)
        return count;

        if(Rabin_Karp(source+a, b) == 1)
        return count+1;

        return -1;
    }
};

### Approach 3: KMP ( Knuth-Morris-Pratt )

# Time complexity : O(M+N)
# Space complexity : O(N) (prefix LPS array)

class Solution {
    private:
    int KMP_search(string s, string p)
    {
        int m = s.size();
        int n = p.size();
//longest proper prefix:longest "prefix" is same as "suffix"
vector<int> lps(n,0);
int len=0, i=1;
while(i<n){
    // if match happen
    if(p[len] == p[i])
    {
        len++;
        lps[i] = len;
        i++;
    }
    else{
        if(len != 0)
        {
            len = lps[len-1];
        }
        else{
            lps[i] = 0;
            i++;
        }
    }
}

i=0;
int j=0;
while(i<m && j<n){
    if(s[i] == p[j]){
        i++;
        j++;
        if(j==n){
            return true;
        }
    }
    else{
        if(j!=0){
            j = lps[j-1];
        }
        else{
            i++;
        }
    }
}
return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int count = 1;
        string source = a;
        while(source.size() < b.size()){
            source += a;
            count++;
        }
        // edge cases 
        if(source == b)
        {
            return count;
        }
        if(KMP_search(source, b) == 1){
            return count;
        }
        if(KMP_search(source+a, b) == 1){
            return count+1;
        }
        return -1;
    }
};

  
