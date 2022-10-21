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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        auto head = res;
        int rem = 0;
        
        while(l1 && l2){
            int sum = l1->val + l2->val + rem;
            res->next = new ListNode(sum%10);
            rem = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            res = res->next;
        }
        
        while(l1){
            int sum = l1->val + rem;
            res->next = new ListNode(sum%10);
            rem = sum/10;
            l1 = l1->next;
            res = res->next;
        }
        while(l2){
            int sum = l2->val + rem;
            res->next = new ListNode(sum%10);
            rem = sum/10;
            l2 = l2->next;
            res = res->next;
        }
        
        if(rem)
            res->next = new ListNode(rem);
        
        return head->next;
    }
};