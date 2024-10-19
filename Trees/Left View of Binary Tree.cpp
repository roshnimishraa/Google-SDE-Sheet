Time Complexity: O(N) because each node is visited once during the traversal, where N is the number of nodes in the tree.

Space Complexity: O(H) where 𝐻 is the height of the tree, due to the recursive stack space used in the function calls (maximum height in case of a skewed tree).

void solve(Node* root, vector<int> &ans, int level)
{
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->left, ans,level+1);
    solve(root->right, ans, level+1);
}
vector<int> leftView(Node *root)
{
 vector<int> ans;
 solve(root, ans, 0);
 return ans;
}
