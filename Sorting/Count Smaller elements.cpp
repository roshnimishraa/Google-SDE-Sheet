### Approach 1: Brute Force (Nested Loops)

Time Complexity: O(N^2)
Space Complexity: O(N)

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
          int n = nums.size();
        vector<int> ans(n,0);
      
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j] < nums[i])
                {
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};
