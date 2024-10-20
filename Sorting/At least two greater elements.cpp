### Approach 1: Brute Force

Time Complexity: O(n2), As we are running a loop of size n2, and at last we are sorting the array, So the total complexity is O(n2+NlogN) ~ O(n2).
Space Complexity: O(n), As we are using array to store the result.

class Solution {
  public:
    vector<int> findElements(vector<int> arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j] > arr[i])
                {
                    count++;
                }
            }
                if(count >= 2){
                    ans.push_back(arr[i]);
                }
            
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

### Approach 2: Using Sorting 

Time Complexity: O(nlogn), As we sort the array which takes NlogN time and we also traverse the array once, so the total complexity becomes O(nlogn+n) ~ O(nlogn).
Space Complexity: O(n), As we are using array to store the result.

class Solution {
  public:
    vector<int> findElements(vector<int> arr) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int n = arr.size();
        for(int i=0;i<n-2;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
