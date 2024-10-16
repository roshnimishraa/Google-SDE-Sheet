Time Complexity: O(n)
Space Complexity: O(1)

/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
 Node *newNode = new Node(data);
 if(head->data > data) {
     newNode->next = head;
     return newNode;
 }
 else {
     
     Node *curr =head;
     while(curr->next != NULL && curr->next->data <= data)
 {
     curr = curr->next;
 }
 newNode -> next = curr->next;
 curr->next = newNode;
 }
 return head;
    }
};
