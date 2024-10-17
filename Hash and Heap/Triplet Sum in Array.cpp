Time complexity: O(n^2), There are only two nested loops traversing the array, so time complexity is O(n^2). Two pointers algorithm takes O(n) time and the first element can be fixed using another nested traversal.
Auxiliary Space: O(1), As no extra space is required.
  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
    set<vector<int>> s;
    vector<vector<int>> output;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
    while(j<k){
        int sum = nums[i]+nums[j]+nums[k];
        if(sum == target){
        s.insert({nums[i], nums[j], nums[k]});
        j++;
        k--;
        }
        else if(sum < target){
            j++;
        }
        else{
            k--;
        }
    }
    }
    for(auto it: s){
        output.push_back(it);
    }
return output;
    }
};
