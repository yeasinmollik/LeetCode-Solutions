class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head->next)
            return;
        
        // Find the middle node
        auto fast = head, slow = head;
        ListNode* prev;
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        
        //Now reverse the linked list starting from middle node to the end. 
        prev->next = NULL;
        prev = NULL;
        int cnt = 0;
        while(slow){
            auto next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
            cnt++;
        }
        //head of the reversed linked list
        auto head1 = prev;
        
        //Finally, merge those two linked lists starting with head and head1
        prev = NULL;
        while(cnt--){
            if(head){
                auto next = head->next, next1 = head1->next;
                head->next = head1, head1->next = next;
                prev = head1;
                head = next, head1 = next1;
            }
            else{
                prev->next = head1;
            }
        }
    }
};
