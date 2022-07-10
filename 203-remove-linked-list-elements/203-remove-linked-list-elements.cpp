/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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