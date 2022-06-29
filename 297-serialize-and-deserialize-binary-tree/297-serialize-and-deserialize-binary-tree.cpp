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
    // helper function for serialize
    void serializeHelper(TreeNode* root, string &s){
        if(root == NULL){
            s += "-9999 ";
            return;
        }
        
        s += to_string(root->val) + ' ';
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }
    
    
    // split string to integer vector
    vector<int> split(string s){
        vector<int> splited;
        istringstream iss(s);
        string w;
        
        while(getline(iss, w, ' ')){
            if(!w.empty())
                splited.push_back(stoi(w));
        }
        return splited;
    }
    
    TreeNode* deserializeHelper(vector<int> &v, int &idx){
        if(v[idx] == -9999){
            idx++;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(v[idx++]);
        root->left = deserializeHelper(v, idx);
        root->right = deserializeHelper(v, idx);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vals = split(data);
        int idx = 0;
        return deserializeHelper(vals, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));