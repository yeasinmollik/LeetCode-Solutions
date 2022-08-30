
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> v;
        treeToVector(root, key, v);
        return vectorToTree(0, v.size() - 1, v);
    }
    
    void treeToVector(TreeNode* root, int key, vector<int> &v){
        if(!root)
            return;
        
        treeToVector(root->left, key, v);
        
        if(root->val != key)
            v.emplace_back(root->val);
        
        treeToVector(root->right, key, v);
    }
    
    TreeNode* vectorToTree(int l, int r, vector<int> &v){
        if(l > r)
            return NULL;
        
        int m = (l + r)/2;
        TreeNode *root = new TreeNode(v[m]);
        root->left = vectorToTree(l, m - 1, v);  
        root->right = vectorToTree(m + 1, r, v);
        return root;
    }
};