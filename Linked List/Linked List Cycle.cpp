### Approach : Slow and fast pointer 

Time Complexity: O(N)
Space Complexity : O(1) 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow=head;
if(head==NULL || head->next == NULL) return false;
    while(fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast = fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
    }
};