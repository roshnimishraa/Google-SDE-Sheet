Time Complexity (TC): O(N) because the algorithm visits each node of the binary tree exactly once, where N is the number of nodes.

Space Complexity (SC): O(H) where H is the height of the tree, due to the space used by the recursive call stack. In the worst case of a skewed tree, H can be equal to N, but in a balanced tree, it is O(logN).

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    
    void traverseLeft(Node *root, vector<int> &ans)
{
    //base case 
 if(root == NULL)  return;

 //exclude leaf node
 if(root->left == NULL && root->right == NULL)
 return;

 // insert root 
 ans.push_back(root->data);

 //print root->left 
 if(root->left != NULL){
     traverseLeft(root->left,ans);

 }
 else{
     traverseLeft(root->right,ans);
 }
}

void traverseLeaf(Node *root, vector<int> &ans)
{
    //base case 
    if(root== NULL) return;

if(root->left == NULL && root->right == NULL)
{
    ans.push_back(root->data);
    return;
}

// move left and right 
traverseLeaf(root->left,ans);
traverseLeaf(root->right,ans);
}

void traverseRight(Node *root,vector<int> &ans)
{
 //base case 
 if(root == NULL) return;

 //exclude leaf node 
 if(root->left == NULL && root->right == NULL){
     return;
 }

 //print right 
 if(root->right != NULL){
     traverseRight(root->right,ans);

 }
 else{
     traverseRight(root->left,ans);
 }

 //reverse ans print 
 ans.push_back(root->data);
 
}

public:
    vector <int> boundary(Node *root)
    {
        
    	vector<int> ans;
    if(root == NULL)  return ans;

 //1. print root 
 ans.push_back(root->data);

 //2. left part print/store
 traverseLeft(root->left,ans);

 //3. Traverse Leaf nodes 
 //leaf node can be in leaf subtree and right subtree 
 //left subtree nodes
 traverseLeaf(root->left,ans);

 //right subtree leaf nodes
 traverseLeaf(root->right,ans);

 //4. right subtree 
traverseRight(root->right,ans);
return ans;
}

};
