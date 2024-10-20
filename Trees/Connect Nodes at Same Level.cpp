### Approach 1 : Recursion

Time Complexity: O(N)
Space Complexity: O(log N) (balanced), O(N) (skewed).


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
    if(root->left != NULL)
    {
        root->left->next = root->right;
    }
    if(root->right != NULL && root->next != NULL)
    {
 root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
    return root;
    }
};


### Approach 2: Iterative 

Time Complexity: O(N)
Space Complexity: o(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* curr = q.front();
                q.pop();
                if(i != n-1) 
                {
                    curr->next = q.front();
                }
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};




