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
  private:
    // Convert BST to Sorted DLL (In-place)
    void convertIntoSortedDLL(Node* root, Node* &head) {
        // base case
        if(root == NULL) 
            return;
        
        convertIntoSortedDLL(root->right, head); // Right subtree
        
        // Adjust pointers for DLL
        root->right = head; // Connect the current node to the DLL
        if(head != NULL) {
            head->left = root;
        }
        
        head = root; // Move the head to current node
        
        convertIntoSortedDLL(root->left, head); // Left subtree
    }
  
    // Merge two sorted doubly linked lists into one
    Node* mergeSortedLL(Node* head1, Node* head2) {
        Node* head = NULL;
        Node* tail = NULL;
        
        while(head1 != NULL && head2 != NULL) {
            if(head1->data < head2->data) {
                if(head == NULL) {
                    head = head1;
                    tail = head1;
                    head1 = head1->right;
                } else {
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right;
                }
            } else {
                if(head == NULL) {
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                } else {
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            }
        }
        
        // Attach remaining nodes
        while(head1 != NULL) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
        while(head2 != NULL) {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
        
        return head;
    }
  
    // Count nodes in the DLL
    int countNodes(Node* head) {
        int count = 0;
        Node* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->right;
        }
        return count;
    }

    // Convert Sorted DLL to Balanced BST
    Node* sortedLLToBST(Node* &head, int n) {
        if(n <= 0 || head == NULL)
            return NULL;
        
        // Recursively build the left subtree
        Node* left = sortedLLToBST(head, n / 2);
        
        // Make the middle node the root
        Node* root = head;
        root->left = left;
        
        // Move the head pointer for the next recursive call
        head = head->right;
        
        // Recursively build the right subtree
        root->right = sortedLLToBST(head, n - n / 2 - 1);
        
        return root;
    }

    // Inorder traversal to get sorted elements in vector
    void inorder(Node* root, vector<int>& result) {
        if(root == NULL)
            return;
        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }

  public:
    vector<int> merge(Node *root1, Node *root2) {
        // Convert both BSTs into sorted doubly linked lists
        Node* head1 = NULL;
        convertIntoSortedDLL(root1, head1);
        if(head1 != NULL) head1->left = NULL;
        
        Node* head2 = NULL;
        convertIntoSortedDLL(root2, head2);
        if(head2 != NULL) head2->left = NULL;
        
        // Merge the two sorted doubly linked lists
        Node* head = mergeSortedLL(head1, head2);
        
        // Convert the merged sorted doubly linked list to BST
        int totalNodes = countNodes(head);
        Node* root = sortedLLToBST(head, totalNodes);
        
        // Extract the in-order traversal of the BST into a vector
        vector<int> result;
        inorder(root, result);
        return result;
    }
};
