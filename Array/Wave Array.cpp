Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution{
    public:
    
    void convertToWave(int n, vector<int>& arr){
        
    for(int i=1;i<n;i+=2)
    {
    //   swap(arr[i-1],arr[i]);    
    int c = arr[i];
    arr[i] = arr[i-1];
    arr[i-1] = c;
    }
        
    }
};
