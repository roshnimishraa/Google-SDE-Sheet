### Approach 1: Brute Force 

Time Complexity: O(N*N ) 
Space Complexity: O(1)

class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(vector<long long> &hist) {
       long long maxArea = 0;
        int n = hist.size();
        for(int i=0;i<n;i++){
            long long minHeight = INT_MAX;
            for(int j=i;j<n;j++){
                  minHeight = min(minHeight,hist[j]);
                long long width = j-i+1;
             maxArea = max(maxArea,minHeight*width);
            }
        }
        return maxArea;
    }
};

### Approach 2: 
