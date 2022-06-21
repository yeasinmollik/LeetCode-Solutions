class Solution {
public:
    int n, m;
    unordered_map<int, int> pos;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size(), m = postorder.size();
        reverse(postorder.begin(), postorder.end());
        for(int i = 0; i < n; i++)
            pos[inorder[i]] = i;
        return solve(inorder, 0, n-1, postorder, 0);
    }
    
    TreeNode* solve(vector<int> &in, int l, int r, vector<int>& post, int id){
        TreeNode* root = new TreeNode(post[id]);
        int mid = pos[post[id]];
        if(l <= mid-1)
            root->left = solve(in, l, mid-1, post, id + r - mid + 1);
        if(mid + 1 <= r)
            root->right = solve(in, mid + 1, r, post, id + 1);
        return root;
    }
};
