### Approach 1: Better 

Time Complexity: O(N) + O(N), where N = size of the array.
Space Complexity: O(1) as we are not using any extra space.

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
       int count0=0, count1=0, count2=0;
       for(int i=0;i<arr.size();i++)
       {
           if(arr[i] == 0) count0++;
           else if(arr[i] == 1) count1++;
           else count2++;
       }
       
       for(int i=0;i<count0;i++)
       arr[i] = 0;
       for(int i=count0;i<count0+count1;i++)
        arr[i] = 1;
        for(int i=count0+count1;i<n;i++)
        arr[i] = 2;
    }
};

### Approach 2: Optimized (Dutch National Flag Algorithm)

Time Complexity: O(N), where N = size of the given array.
Reason: We are using a single loop that can run at most N times.
Space Complexity: O(1) as we are not using any extra space.

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low=0, mid=0, high = arr.size()-1;
        
        while(mid <= high)
        {
            if(arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1)
        {
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
        }
    }
};
