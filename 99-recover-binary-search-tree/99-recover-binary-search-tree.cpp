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
    bool start = false;
    TreeNode** prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    
    void recoverTree(TreeNode* root) {
        recover(root);
        swapNodes();
    }
    
    void swapNodes(){
        swap(first->val, second->val);
    }
    
    void recover(TreeNode* &curr){
        if(!curr)
            return;
        
        recover(curr->left);
        
        if(!start)
            start = true;
        else{
            if(!first && (*prev)->val >= curr->val)
                first = *prev;
            if(first && (*prev)->val >= curr->val)
                second = curr;
        }
        prev = &curr;
        
        recover(curr->right);
    }
};