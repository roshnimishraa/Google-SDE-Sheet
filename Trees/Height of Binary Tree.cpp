Time Complexity: O(N)
Space Complexity: O(N)

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
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node == NULL) return 0;
  int left= height(node->left);
     int right= height(node->right);
    return max(left,right)+1;
    }
};
