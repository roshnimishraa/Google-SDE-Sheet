### Approach 1 : Brute Force (Recursion)

Time complexity : O(2N) , since we make repeated call for the answer on the same node , where N is number of nodes in tree.
Space complexity : O(1) , since no extra space is required.

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    private:
    int dfs(Node* root)
    {
        if(root == NULL) return 0;
// take child of node 
int take = root->data;
if(root->left != NULL)
{
    take += dfs(root->left->left);
    take += dfs(root->left->right);
}
if(root->right != NULL)
{
    take += dfs(root->right->left);
    take += dfs(root->right->right);
}

// don not include childrent 
int notTake = dfs(root->left) + dfs(root->right);
return max(take,notTake);
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        return dfs(root);
    }
};


### Approach 2: Optimized

Time Complexity : O(N) , since all nodes will be visited at most once, where N is number of nodes in the tree.
Space Complexity : O(N), since we store maximum answer for each subtree in the unordered_map and there are N nodes .

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
//   {maximum sum in take, maximum sum in notTake}
   pair<int,int> maxSumHelper(Node* root)
   {
       if(root == NULL){
           pair<int,int> sum(0,0);
           return sum;
       }
      
    //  calling function for left and right subtree 
     pair<int,int> sum1 = maxSumHelper(root->left);
     pair<int,int> sum2 = maxSumHelper(root->right);
     pair<int,int> sum;
     
    //  current node is included (left and right child are not included)
     sum.first = sum1.second + sum2.second + root->data;
     
    //  current node is excluded (Either left or right child is included)
     sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);
     return sum;
   }
    int getMaxSum(Node *root) 
    {
        pair<int,int> res = maxSumHelper(root);
        return max(res.first, res.second);
    }
};


### Approach 3: Map 

Time complexity: O(N)
Auxiliary Space: O(N)

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    int solve(Node* root, unordered_map<Node*,int> &mp)
    {
        if(root == NULL)
        {
            return 0;
        }
        // if max sum exists in map 
        if(mp[root])
        {
            return mp[root];
        }
// if current node root (root) is included in result 
int take = root->data;
if(root->left != NULL)
{
    take += solve(root->left->left, mp) + solve(root->left->right,mp);
}
if(root->right != NULL)
{
    take += solve(root->right->left,mp) + solve(root->right->right, mp);
}
// if current node (root) is excluded 
int notTake = solve(root->left, mp) + solve(root->right, mp);

// store the max of take and notTake in map
mp[root] = max(take,notTake);
return max(take,notTake);
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        unordered_map<Node*, int> mp;
        return solve(root,mp);
    }
};

