### Approach 1: Stack 

# Time Complexity: O(N), where N is the number of persons.
# Auxiliary Space: O(N) as we are using Stack.

class Solution 
{
    bool knows(vector<vector<int>> &m,int a,int b,int n)
    {
     if(m[a][b]==1) return true;
     return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> st;
// push all elemnets in stack
for(int i=0;i<n;i++)
{
    st.push(i);
}
while(st.size() > 1)
{
int a =st.top();
st.pop();
int b = st.top();
st.pop();
if(knows(m,a,b,n)==true)
{
    // discard A
    st.push(b);
}
else{
    st.push(a);
}
}

int Pcand = st.top();
// Pcand->cel row->0 and col-> 1 except diagonal 
bool rowCheck = false;
int zeroCount;
for(int i=0;i<n;i++)
{
    if(m[Pcand][i]==0){
        zeroCount++;
    }
}
if(zeroCount == n){
    rowCheck = true;
}
bool colCheck =  false;
int oneCount = 0;
for(int i=0;i<n;i++)
{
    if(m[i][Pcand] == 1)
    {
        oneCount++;
    }
}
if(oneCount == n-1){
    colCheck = true;
}
if(rowCheck==true && colCheck==true) return Pcand;
return -1;
 }
};

### Approach 2: Two Pointer (Optimal)

# Time Complexity: O(2 N)
# Space Complexity: O(1) 

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
int n = mat.size();
int top=0, down = n-1;
while(top < down)
{
    // top knows down
    // this can't be celebrity check for other 
    if(mat[top][down] == 1)
    {
        top = top+1;  
    }
    // down know top
    // if(mat[down][top] == 1)
    else 
    {
        down = down-1;
    }
    
}
if(top > down) return -1;
// if top == down -> celebrity
for(int i=0;i<n;i++){
    // check for entire row and entire column except diagonal
   if(i != top)
   {
      if (mat[i][top] == 0
                || mat[top][i] == 1)
                return -1;
   }
}
return top;
    }
};
