Time Complexity: O(n*n), as in the worst case all cells will be visited.
Auxiliary Space: O(n*n), as we are using a vector vis of size n*n. Also max number of cells stored in queue can go up to n*n in worst case.

class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    queue<pair<int,pair<int,int>>> q;
	    vector<vector<int>> vis(N+1, vector<int>(N+1,0));
	    q.push({0, {KnightPos[0]-1, KnightPos[1]-1}});
	    
	    vis[KnightPos[0]-1][KnightPos[1]-1] = 1;
	    
	      int dx[8]={ 2, 2, -2, -2, 1, 1, -1, -1 };
        int dy[8]={ -1, 1, 1, -1, 2, -2, 2, -2 };
        
	    while(!q.empty())
	    {
	        auto it = q.front();
	        int steps = it.first;
	        int row = it.second.first;
	        int col = it.second.second;
	        q.pop();
	        
	   if(row == TargetPos[0]-1 && col == TargetPos[1]-1)
	   {
	       return steps;
	   }
	   
	   for(int i=0;i<8;i++)
	   {
	       int nrow = dx[i] + row;
	       int ncol = dy[i] + col;
	       
	   if(nrow>=0 && nrow<=N && ncol>=0 && ncol<=N && vis[nrow][ncol] == 0)
	   {
	       vis[nrow][ncol] = 1;
	       q.push({steps+1, {nrow, ncol}});
	   }
	       
	   }
	    }
	    
	    return -1;
	}
};
