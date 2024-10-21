### Approach 1: Brute Force

Time Complexity: O(n) where n is the number of elements in the nums vector. The algorithm iterates through the entire vector once.
Space Complexity: O(1). The algorithm uses only a constant amount of extra space regardless of the size of the input vector nums.

class Solution {
public:
    int findMin(vector<int>& arr) {
        int min_ele = arr[0];
        int n = arr.size();  // Get the size of the array
        
        // Traverse the array to find the minimum element
        for (int i = 1; i < n; i++) {  // Start from 1 since min_ele is initialized with arr[0]
            if (arr[i] < min_ele) {
                min_ele = arr[i];
            }
        }
        return min_ele;
    }
};

### Approach 2: Binary Search

Time Complexity: O(logn) - The binary search halves the search space in each recursive call.
Space Complexity: O(logn), Due to recursive stack.

class Solution {
  public:
    int findMin(vector<int>& arr) {
       int mini = 1e9;
       int low=0;
       int high = arr.size()-1;
       while(low<=high)
       {
           int mid = (low+high)/2;
           if(arr[low] <= arr[mid])
           {
               mini = min(mini, arr[low]);
               low = mid+1;
           }
           else{
               mini = min(mini, arr[mid]);
               high = mid-1;
           }
       }
       return mini;
    }
};
