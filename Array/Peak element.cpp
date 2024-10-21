### Approach : Moore’s Voting Algorithm (Best)

Time Complexity: O(n), As two traversal of the array, is needed, so the time complexity is linear.
Auxiliary Space: O(1), As no extra space is required.

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
       int count = 0;
        int element;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(count == 0){
                count = 1;
                element = nums[i];
            }
            else if(nums[i] == element)
            {
                count++;
            }
            else{
                count--;
            }
        }
        int count1=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == element)
            {
                count1++;
            }
            if(count1 > n/2) return element;
        }
        return -1;
    }
};

### Approach 2: Binary Search

Time Complexity: O(logN) where N is the size of the array as we are doing the binary search.
Space Complexity: O(1) , no auxiliary space required.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n-2;
        if(n==1) return 0; //index
 if(nums[0] > nums[1]) return 0;
 if(nums[n-1] > nums[n-2]) return n-1;

 while(low <= high)
 {
    int mid = low + (high-low)/2;
if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
{
    return mid;
}

// increasing 
else if(nums[mid] > nums[mid-1])
{
    low = mid+1;
}
else if(nums[mid] < nums[mid-1])
{
    high = mid-1;
}
 }
 return -1; 
    }
};
