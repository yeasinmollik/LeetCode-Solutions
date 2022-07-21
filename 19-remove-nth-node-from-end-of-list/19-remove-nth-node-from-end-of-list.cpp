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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto first = head, second = head;
        while(n--)
            first = first->next;
        
        auto prev = head;
        while(first)
            first = first->next, prev = second, second = second->next;
        
        if(second == head) // means we are asked to remove the 1st node
            head =  head->next;
        else
            prev->next = second->next;
        return head;
    }
};