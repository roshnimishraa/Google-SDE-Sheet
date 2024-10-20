### Approach 1 : Brute Force

Time Complexity: O((n1+n2)log(n1+n2)) 
Space Complexity: O(n1+n2)

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void r(Node* root, vector<int> &v)
    {
        if(root == NULL) return;
        v.push_back(root->data);
        r(root->left, v);
        r(root->right, v);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> res;
        r(root1,res);
        r(root2, res);
        sort(res.begin(),res.end());
        return res;
    }
};

### Approach 2: Optimized

1. Merge 2 sorted Doubly Linked List(Merge two sorted linked lists)
Time Complexity: O(M+N), M is the size of the first tree and N is the size of the second tree
Auxiliary Space: O(1)

2. Convert BST into sorted Doubly Linked List(Flatten a binary tree into linked list)
Time Complexity: O(N),N is the size of the tree
Auxiliary Space: O(H),H is the height of the tree 

Steps 
1. Convert a BST into sorted DLL
2. Merge 2 sorted Linked List
3. Sorted LL -> BST 
