Time Complexity: O(N) because each node is visited once during the traversal, where N is the number of nodes in the tree.
Space Complexity: O(H) where H is the height of the tree, due to the recursive stack space used in the function calls (maximum height in case of a skewed tree).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
void helper(TreeNode *root,int level,vector<int> &ans)
{
    if(root == NULL) return;
if(ans.size() == level) 
ans.push_back(root->val);

// reverse preorder traversal 
// root right left 
helper(root->right,level+1,ans);
helper(root->left,level+1,ans);
}
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
  helper(root,0,ans);
  return ans;
    }
};
