### Approach 1: Unordered_map

Time Complexity: O(N)
Space Complexity: O(N)

class Solution {
  public:
    int singleElement(int arr[] ,int n) {
unordered_map<int,int> mp;
for(int i=0;i<n;i++)
{
    mp[arr[i]]++;
}
for(auto it: mp)
{
    if(it.second == 1)
    {
        return it.first;
    }
}
return -1;
    }
};

### Approach 2: Using Bit Manipulation

Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
      int ans=0;
      for(int i=0;i<32;i++)
      {
          int bit = 1<<i;
          int count=0;
          for(int j=0;j<N;j++)
          {
              if(bit & arr[j])
              {
                  count++;
              }
          }
          if(count % 3 !=0)
                ans = ans|bit;
      }
      return ans;
    }
};
