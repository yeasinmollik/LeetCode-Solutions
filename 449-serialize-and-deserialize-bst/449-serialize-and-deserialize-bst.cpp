/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelper(TreeNode* root, string &s){
        if(root == NULL){
            s += "-1 ";
            return;
        }
        
        s += to_string(root->val) + " ";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        cout << s << endl;
        return s;
    }
    
    //split a string into a vector of integers
    vector<int> split(string &s){
        vector<int> v;
        istringstream iss(s);
        string val;
        
        while(getline(iss, val, ' '))
            if(!val.empty())
                v.push_back(stoi(val));
        return v;
    }
    
    // generates a binary search tree from its preorder traversal 
    TreeNode* deserializeHelper(vector<int>& preorder, int &idx){
        if(preorder[idx] == -1){
            idx++;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = deserializeHelper(preorder, idx);
        root->right = deserializeHelper(preorder, idx);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder = split(data);  
        int idx = 0;
        return deserializeHelper(preorder, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;