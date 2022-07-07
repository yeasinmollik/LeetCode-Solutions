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
    ListNode* sortList(ListNode* head) {
        int zero = 1e5;
        
        int cnt[200010] = {};
        auto curr = head;
        while(curr){
            cnt[curr->val + zero]++;
            curr = curr->next;
        }
        
        curr = head;
        for(int i = -zero; i <= zero ; i++){
            for(int j = 0; j < cnt[i + zero]; j++){
                curr->val = i;
                curr = curr->next;
            }
        }
        return head;
    }
};