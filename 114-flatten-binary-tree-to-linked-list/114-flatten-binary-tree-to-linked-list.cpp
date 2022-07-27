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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        int inf = 1e9;
        TreeNode* flat = new TreeNode(inf);
        TreeNode *newRoot = flat;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto curr = s.top();
            s.pop();
            
            
            flat->right = new TreeNode(curr->val);
            flat = flat->right; 
            
            if(curr->right)
                s.push(curr->right);
            if(curr->left)
                s.push(curr->left);
        }
        newRoot = newRoot->right;
        root->left = NULL;
        root->right = NULL;
        copy(newRoot->left, root->left);
        copy(newRoot->right, root->right);
    }
    
    void rec(TreeNode* root){
        if(!root){
            cout << "NULL" << " ";
            return;
        }
        cout << root->val << " ";
        rec(root->left);
        rec(root->right);
    }
    
    void copy(TreeNode* a, TreeNode* &b){
        if(!a)
            return;
        b = new TreeNode(a->val);
        copy(a->left, b->left);
        copy(a->right, b->right);
    }
};