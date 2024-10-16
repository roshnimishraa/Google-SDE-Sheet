Time Complexity: O(NlogN)
Space Complexity: O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        if(nums.size() == 0) return 0;
    unordered_set<int> st;
    for(int i=0;i<nums.size();i++)
    {
        st.insert(nums[i]);
    }
    for(auto it:st)
    {
    if(st.find(it-1) == st.end())
    {
        int count= 1;
        int x = it;
// find next of first ele 
while(st.find(x+1)!=st.end())
{
    x = x+1;
    count++;
}
longest = max(longest,count);
    }
    }
    return longest;
    }
};
