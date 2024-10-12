### Approach 1: Brute Force

# Time Complexity: O(N^2)
# Space Complexity: O(256)

class Solution {
    bool containsAllCharacters(string &s, string &t){
 int count[256] = {0};
    for(char it: t){
        count[it]++;
    }
    for(char it: s){
        if(count[it] > 0){
            count[it]--;
        }
    }
    for(int i=0;i<256;i++){
        if(count[i] > 0){
            return false;
        }
    }
    return true;
    }
public:
    string minWindow(string s, string t) {
   int n = s.length();
   int m = t.length();
   string ans="";
   int minLen = INT_MAX;
   for(int i=0;i<n;i++)
   {
    for(int j=i;j<n;j++)
    {
 int k= j-i+1;
 string substr = s.substr(i,k);
 if(containsAllCharacters(substr,t))
 {
    int currLen = substr.length();
    if(currLen < minLen){
        minLen = currLen;
        ans = substr;
    }
 }
    }
   }
   return ans;
    }
};

### Approach 2: Better Approach (Two Pointers)

# Time Complexity : O(m+n) where m = length of s and n = length of t
# Space Complexity : O(n)

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        map<char, int> mp;
        for(char &ch : t)
        {
            mp[ch]++;
        }
        int requiredCount = t.length();
        int i=0, j=0;
        int minStart = 0;
        int minWindow = INT_MAX;
    while(j<n)
    {
        char ch_j = s[j];
        if(mp[ch_j] > 0){
            requiredCount--;
        }
        mp[ch_j]--;

        while(requiredCount == 0){
            if(minWindow > j-i+1)
            {
                minWindow = j-i+1;
                minStart = i;
            }
            char ch_i = s[i];
            mp[ch_i]++;
            if(mp[ch_i] > 0)
            requiredCount++;
            i++;
        }
        j++;
    }
    return minWindow == INT_MAX ? "": s.substr(minStart, minWindow);
    }
};

