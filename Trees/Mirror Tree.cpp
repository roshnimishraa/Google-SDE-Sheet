### Approach 1 : Recursion

Time Complexity: O(N) because each node is visited once.
Space Complexity: O(H) due to the recursive call stack, where H is the height of the tree.

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
     if(node == NULL) return;
     swap(node->left,node->right);
     mirror(node->left);
     mirror(node->right);
    }
};


### Approach 2: Iterative (Queue) 

Time Complexity: O(N) because each node is processed once. 
Space Complexity: 𝑂 ( 𝑊 ) O(W) where 𝑊 W is the maximum width of the tree, which can be O(N) in the worst case for a complete binary tree, but typically less than N.
  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
      queue<Node*> q;
      q.push(node);
      while(!q.empty())
      {
         Node* curr = q.front();
        q.pop();
swap(curr->left,curr->right);
if(curr->left!= NULL)
{
    q.push(curr->left);
}
if(curr->right!=NULL)
{
    q.push(curr->right);
}
      }
    }
};

