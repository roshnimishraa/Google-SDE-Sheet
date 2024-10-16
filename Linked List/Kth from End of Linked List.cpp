Time Complexity: O(M) where M is the length of the linked list
Auxiliary Space: O(1)

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        if(head == NULL){
          return 0;
      }
     Node *first = head;
     Node *second  = head;
    
for(int i=1;i<k;i++){
     first = first->next;
    if(first == NULL) {
        return -1;
    }
}


while(first->next != NULL){
    first = first ->next;
    second = second ->next;
}
return second->data;
    }
};
