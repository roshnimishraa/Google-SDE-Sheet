### Approach 1: Brute Force 

Time Complexity : O(n^2)
Auxiliary Space: O(1)
  
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
         int count=0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum += arr[j];
                if(sum == k)
                count++;
            }
        }
        return count;
    }
};

### Approach 2: 

Time Complexity: O(n) 
Auxiliary Space: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> mp;
        int count =0;
        mp.insert({0,1});
    int sum = 0; //prefix sum
    for(int i =0;i<n;i++)
    {
        sum += nums[i];
        if(mp.find(sum-k) != mp.end())
        {
            count += mp[sum-k];
        }
        mp[sum]+=1; //add or update in map
    }
    return count;
    }
};
