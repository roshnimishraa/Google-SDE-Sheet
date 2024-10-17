### Approach : Sorting + Set

Time Complexity: O(N^2)
Space Complexity: O(N)

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
