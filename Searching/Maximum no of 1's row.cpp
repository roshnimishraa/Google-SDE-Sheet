### Approach 1: Using Nested Loops

class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
         for(int j=0;j<M;j++){
             for(int i=0;i<N;i++){
                 if(Mat[i][j] == 1){
                     return i;
                 }
             }
         }
        
        }
};

### Approach 2: Using Binary Search

class Solution
{
    int solve(vector<int> &v){
        int low = 0, high = v.size()-1;
        int ans=-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(v[mid] == 1)
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans == -1 ? 0 : v.size()-ans;
    }
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
           int rowAns = -1;
           int maxOne = INT_MIN;
           for(int i=0;i<N;i++)
           {
               int NoOfOnes = solve(Mat[i]);
               if(maxOne < NoOfOnes)
               {
                   maxOne = NoOfOnes;
                   rowAns = i;
               }
           }
         
           return rowAns;
        }
};
