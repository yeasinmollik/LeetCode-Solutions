class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head, *prevLeft = NULL; 
        for(int i = 0; i + 1< left; i++)
            prevLeft = curr, curr = curr->next;
        
        ListNode *prev = NULL, *next, *first = curr;
        for(int i = left; i <= right; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(prevLeft)
            prevLeft->next = prev;
        else
            head = prev;
        
        first->next = curr;
        return head;
    }
};