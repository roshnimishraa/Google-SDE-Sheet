### Approach : Recursion 

Time complexity: O(N) where n is the number of nodes.
Space complexity: O(N), auxiliary space.

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

   
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL || root->data == n1 || root->data == n2)
       {
           return root;
       }
       Node* left = lca(root->left, n1,n2);
       Node* right = lca(root->right, n1, n2);
       
       if(left == NULL)
       {
           return right;
       }
       else if(right == NULL)
       {
           return left;
       }
       else{
        //   left and right are not null
        return root;
       }
    }
};