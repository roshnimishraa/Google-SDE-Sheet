### Approach 1 : Brute Force 
Time Complexity: O(N)
Space Complexity : O(N) where N is the number of nodes in the Binary Search Tree as additional space is required to store the elements of the BST in an array.

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
    void solve(TreeNode* root, int k, vector<int> &ans)
    {
        if(root == NULL) return;
    solve(root->left, k, ans);
    ans.push_back(root->val);
    solve(root->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
vector<int> ans;
solve(root, k, ans);
return ans[k-1];
    }
};

### Approach 2 : Optimal Approach

Time Complexity: O(N)
Space Complexity: O(1) 

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
    void inorder(TreeNode* root, int &counter,int k, int &kthSmallest)
    {
        if(root == NULL || counter >= k) return;
    inorder(root->left, counter, k,kthSmallest);
    counter++;
    if(counter == k)
    {
        kthSmallest = root->val;
        return;
    }
    inorder(root->right, counter, k,kthSmallest);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
      int kthSmallest = INT_MIN;
      int counter=0;
      inorder(root, counter, k, kthSmallest);
      return kthSmallest;
    }
};
