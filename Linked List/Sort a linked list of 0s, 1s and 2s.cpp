Time Complexity: O(n), where n is the number of nodes in the linked list.
Auxiliary Space: O(1)

/* 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
 int zeroCount = 0 ;
   int oneCount = 0 ;
   int twoCount = 0 ;

Node *curr =head;
while(curr != NULL){
    if(curr -> data == 0){
        zeroCount++;
    }
    else if(curr -> data == 1){
        oneCount++;
    }
    else if(curr->data == 2){
        twoCount++;
    }
 
        curr = curr->next;
   
}

 curr = head;
 while(curr != NULL){
     if(zeroCount !=0){
         curr->data =0;
         zeroCount--;
     }
     else if(oneCount !=0){
         curr->data =1;
         oneCount--;
     }
     else if(twoCount !=0){
         curr->data =2;
         twoCount--;
     }
   
         curr = curr->next;
    
 }
return head;
        
    }
};
