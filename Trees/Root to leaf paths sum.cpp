### Approach : Recursion

Time Complexity (TC): O(n)
This is because the algorithm performs a DFS traversal of the binary tree, visiting each node exactly once, where n is the total number of nodes in the tree.

Space Complexity (SC): O(h)
Here, h is the height of the tree. This is the space required by the recursion stack. In the worst case (if the tree is skewed),
the space complexity could be O(n), but in a balanced tree, it would be O(log n).


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
    int solve(TreeNode*root, int curr)
    {
          if(root == NULL) return 0;
        curr = curr*10 + (root->val);
        if(root->left == NULL && root->right == NULL)
        {
            return curr;
        }

        // call function for left subtree and right subtree
    int left = solve(root->left, curr);
    int right = solve(root->right, curr);
    return left+right;
    }
public:
    int sumNumbers(TreeNode* root) {
      return solve(root,0);
    }
};
