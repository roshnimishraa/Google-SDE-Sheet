Time Complexity: O(N)
Space Complexity: O(H), where H is the height of the tree. Worst case: O(N), Best case: O(log N).

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
    int helper(TreeNode* root,int &res)
    {
        if(root == NULL) return 0;
int left = max(0,helper(root->left,res));
int right = max(0,helper(root->right,res));
res = max(res,left+right+root->val);
return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
     int res = INT_MIN;
     helper(root,res);
     return res;   
    }
};
