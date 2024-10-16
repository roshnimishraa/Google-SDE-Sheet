### Approach : Slow and Fast pointer

Time Complexity: O(N) 
Space Complexity: O(1) 
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
   
    int countNodesinLoop(Node *head) {
          int count=0;
    
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){
            int count=1;
            fast=fast->next;
            while(fast!=slow)
            {
                count++;
                fast=fast->next;
            }
            return count;
        }
    }
    
    return count;
    }
};
