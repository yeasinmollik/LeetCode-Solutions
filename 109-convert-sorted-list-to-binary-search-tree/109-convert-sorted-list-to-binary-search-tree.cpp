/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head){
            v.emplace_back(head->val);
            head = head->next;
        }
        
        return build(0, v.size() - 1, v);
    }
    
    TreeNode* build(int l, int r, vector<int> &v){
        if(l > r)
            return NULL;
        
        int m = (l + r)/2;
        TreeNode *root = new TreeNode(v[m]);
        root->left = build(l, m - 1, v);
        root->right = build(m + 1, r, v);
        return root;
    }
};