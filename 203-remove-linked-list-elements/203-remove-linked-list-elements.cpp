class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // dummy head node to handle edge cases
        // and to make the code more concise
        auto dummy_head = new ListNode(-1);
        dummy_head->next = head;
        
        auto curr = head, prev = dummy_head;
        while(curr){
            if(curr->val == val)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;            
        }
        
        return dummy_head->next;
    }
};