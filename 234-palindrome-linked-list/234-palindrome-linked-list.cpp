//1. Find the midpoint
//2. Reverse the linked-list after the midpoint
//3. Finally, check if 1st half equals to second half
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        //Now, slow is the midpoint of the given linked-list
        
        
        ListNode *prev = NULL, *next;
        while(slow){
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        ListNode *newHead = prev;
        while(head && newHead){
            if(head->val != newHead->val)
                return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};