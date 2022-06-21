class Solution {
public:
    unordered_map<int, int> index_of;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            index_of[inorder[i]] = i;
        
        reverse(postorder.begin(), postorder.end());
        return getTree(inorder, 0, inorder.size() - 1, postorder, 0);
    }
    
    TreeNode* getTree(vector<int>& inorder, int l, int r, vector<int>& postorder, int id){
        TreeNode* root = new TreeNode(postorder[id]);
        int mid = index_of[postorder[id]];
        
        if(l <= mid - 1)
            root->left = getTree(inorder, l, mid - 1, postorder, id + r - mid + 1);
        
        if(mid + 1 <= r)
            root->right = getTree(inorder, mid + 1, r, postorder, id + 1);
        
        return root;
    }
};
