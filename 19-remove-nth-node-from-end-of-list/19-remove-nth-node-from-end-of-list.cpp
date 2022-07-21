class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto first = head, second = head;
        while(n--)
            first = first->next;
        auto prev = head;
        while(first)
            first = first->next, prev = second, second = second->next;
    
        if(second == head) // first node has to be removed
            head = head->next;
        else
            prev->next = second->next;
        return head;
    }
};