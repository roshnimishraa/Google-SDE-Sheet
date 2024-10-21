### Approach 1: Backtracking

Time Complexity: O(N*M*8^k)
Space Complexity: O(K)

class Solution {
    private:
    bool isValid(int x, int y, int n, int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    
    bool helper(vector<vector<char>> &grid, int n, int m, string &word, 
    int index, int x, int y, int dx, int dy)
    {
        // base case
        if(index == word.size())
        {
            return true;
        }
        if(isValid(x,y,n,m) && word[index] == grid[x][y])
        {
            int newX = x+dx;
            int newY = y+dy;
            return helper(grid,n,m,word, index+1, newX,newY,dx, dy);
        }
        return false;
    }
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
       vector<vector<int>> ans;
       int x[] = {1,-1,0,0,1,1,-1,-1};
       int y[] = {0,0,1,-1,1,-1,1,-1};
       
       int n = grid.size();
       int m = grid[0].size();
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j] == word[0])
               {
                   for(int k=0;k<8;k++)
                   {
                       if(helper(grid,n,m,word,0,i,j,x[k], y[k]))
                       {
                           ans.push_back({i,j});
                           break;
                       }
                   }
               }
           }
       }
       return ans;
	}
};

### Approach 2:

