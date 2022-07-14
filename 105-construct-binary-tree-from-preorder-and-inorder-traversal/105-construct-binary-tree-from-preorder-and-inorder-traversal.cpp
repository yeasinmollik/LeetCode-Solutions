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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> idx;
        for(int i = 0; i < inorder.size(); i++)
            idx[inorder[i]] = i;
        TreeNode* root;
        int i = 0;
        buildTree(root, preorder,i, idx, 0, inorder.size() - 1, inorder);
        return root;
    }
    
    void buildTree(TreeNode* &curr, vector<int> &pre, int &i,  unordered_map<int, int> &idx, int l, int r, vector<int> &in){
        
        curr = new TreeNode(pre[i]);
        int mid = idx[pre[i]];
        
        if(mid - 1 >= l)
            buildTree(curr->left, pre, ++i, idx, l, mid -1, in);
        if(mid + 1 <= r)
            buildTree(curr->right, pre, ++i, idx, mid + 1, r, in);
    }
};