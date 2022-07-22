class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<int> pre;
        int num = 0, cnt = 0;
        vector<int> vals, levels = {0};
        
        for(int i = 0; i < traversal.size(); i++){
            if(traversal[i] == '-') {
                if(num > 0)
                    vals.push_back(num), num = 0;
                cnt++;
            }
            else{
                if(cnt > 0)
                    levels.push_back(cnt), cnt = 0;
                num = num * 10 + traversal[i] - '0';                
            }
        }
        vals.push_back(num);
        
        int lid = 0, vid = 0;
        return build(vals, levels, lid, vid, 0);
    }
    
    TreeNode* build(vector<int> &vals, vector<int> &levels, int &lid, int &vid, int level){
        if(lid == levels.size() || levels[lid] != level)
            return NULL;
        
        TreeNode *root = new TreeNode(vals[vid]);
        vid++, lid++;
        root->left = build(vals, levels, lid, vid, level + 1);
        root->right = build(vals, levels, lid, vid, level + 1);
        return root;
    }
};