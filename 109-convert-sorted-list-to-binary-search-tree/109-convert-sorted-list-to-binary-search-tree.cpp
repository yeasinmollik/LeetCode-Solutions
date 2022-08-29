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