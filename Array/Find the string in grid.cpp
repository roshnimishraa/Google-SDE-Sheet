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

Time Complexity:  O(row*col*8*k) since the time complexity of the searchWord method is linear in the size of the grid (row x col) and the length of the word (k).
Space Complexity:  O(row*col), The space complexity mainly consists of the auxiliary space used for the ans list.


class Solution {
    private:

    bool helper(vector<vector<char>> &grid, int row, int col, string &word, 
    vector<int> &x, vector<int> &y)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[row][col] != word[0])
        {
            return false;    
        }
        int len = word.size();
        
     // Search word in all 8 directions starting from (row,col)
        for(int dir=0;dir<8;dir++)
        {
            int newX = row + x[dir];
            int newY = col + y[dir];
            int k;
    //first character is already checked match remaining characters 
            for( k=1;k<len;k++)
            {
                if(newX >= n || newX<0 || newY>=m || newY<0)
                break;
                
                // if not matched 
                if(grid[newX][newY] != word[k])
                break;
                
                // moving in particular direction
                newX += x[dir];
                newY += y[dir];
            }
            
        // if all character matched then value of must 
        // be equal to length of word
        
        if(k == len)
        return true;
        }
        return false;
    }
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
	{
	   int n = grid.size();
	   int m = grid[0].size();
	  	vector<int>x = { -1, -1, -1, 0, 0, 1, 1, 1 };
		vector<int>y = { -1, 0, 1, -1, 1, -1, 0, 1 };
		
	   vector<vector<int>> ans;
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       {
	           if(helper(grid,i,j,word,x,y))
	           {
	               ans.push_back({i,j});
	           }
	       }
	   }
	   return ans;
	}
};
