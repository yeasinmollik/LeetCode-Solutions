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
    int n, m;
    unordered_map<short, short> pos;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size(), m = postorder.size();
        reverse(postorder.begin(), postorder.end());
        for(int i = 0; i < n; i++)
            pos[inorder[i]] = i;
        return solve(inorder, 0, n-1, postorder, 0);
    }
    
    TreeNode* solve(vector<int> &in, int l, int r, vector<int>& post, int id){
        TreeNode* root = new TreeNode(post[id]);
        int m = pos[post[id]];
        if(l <= m-1)
            root->left = solve(in, l, m-1, post, id + r - m + 1);
        if(m + 1 <= r)
            root->right = solve(in, m + 1, r, post, id + 1);
        return root;
    }
};
