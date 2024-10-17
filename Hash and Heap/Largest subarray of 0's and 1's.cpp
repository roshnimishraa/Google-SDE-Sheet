### Approach 1: Brute Force

Time Compelxity : O(n^2)
Space Complexity : O(1)
  
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen=0;
        for(int i=0;i<nums.size();i++)
        {
            int zeroes = 0, ones =0;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j] == 0){
                    zeroes++;
                }
                else{
                    ones++;
                }
                if(zeroes == ones){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};

### Approach 2: 
TC : O(n^2)
SC : O(1)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int maxLen = 0, startIndex;
        for(int i=0;i<n-1;i++)
        {
            sum = (nums[i] == 0) ? -1 : 1;
        for(int j=i+1;j<n;j++)
        {
            (nums[j] == 0) ? (sum += -1) : (sum += 1);
            if(sum == 0 && maxLen < j-i+1)
            {
                maxLen = j-i+1;
                startIndex =i;
            }
        }
        }
return maxLen;
    }
};

### Approach 3: Using map

Time Complexity: O(N) where n is the size of an array.
Space Complexity: O(n) as map used.
  
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        mp.insert({0,-1});
        int n = nums.size();
        int maxLen=0, count=0;
        for(int i=0;i<n;i++)
        {
            count += (nums[i] == 1) ? 1 : -1;
            if(mp.find(count) != mp.end())
            {
                maxLen = max(maxLen, i - mp[count]);
            }
            else{
                mp.insert({count, i});
            }
        }
        return maxLen;
    }
};
