### Approach : Recursion 

Time Complexity: O(N), As we are traversing through every nodes of the tree, where N is the number of nodes in the tree.
Space Complexity: O(H), As the size of the recursive call stack can be maximum of the height of the tree, Where H is the height of the tree.

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    private:
  int maxPathSumHelper(Node* root, int &res)
    {
        if(root == NULL){
            return 0;
        }
        // left node return its value 
        if(root->left == NULL && root->right == NULL)
        {
            return root->data;
        }
        int left = maxPathSumHelper(root->left, res);
        int right = maxPathSumHelper(root->right, res);
    
    if(root->left != NULL && root->right != NULL)
    {
        res = max(res, left + right + root->data);
        return max(left, right) + root->data;
    }
    return (root->left==NULL) ? right + root->data : left + root->data;
    }
public:
    int maxPathSum(Node* root)
    {
        int res = INT_MIN;
        int h = maxPathSumHelper(root, res);
        if(root->left == NULL || root->right == NULL)
        {
            res = max(res, h);
        }
        return res;
    }
};
