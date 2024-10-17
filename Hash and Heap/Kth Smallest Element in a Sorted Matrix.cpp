### Approach 1: Min-Heap

Time Complexity: O(N2* log(N2)); since insertion in priority queue takes log N time and we have inserted N^2 elements.
Auxiliary Space :  O(N^2)
  
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // min-heap
        priority_queue<int,vector<int>, greater<int>> pq;
int n = matrix.size();
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    {
        pq.push(matrix[i][j]);
    }
}

int count=0;
while(!pq.empty()){
    int curr = pq.top();
    pq.pop();
    count++;
    if(count == k)
    {
        return curr;
    }
}
return -1;
    }
};


### Approach 2: Binary Search 

Time complexity: O(n logn logn)
Space complexity: O(1)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
    int low = matrix[0][0];
    int high = matrix[n-1][m-1];
    while(low <= high)
    {
        int mid = low + (high-low)/2;
    int count=0;
    for(int i=0;i<m;i++)
    {
        count += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
    }
    if(count < k){
        low = mid+1;
    }
    else {
        high = mid-1;
    }
    }
    return low;
    }
};

