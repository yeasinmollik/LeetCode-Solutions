class Solution {
public:
    struct TrieNode{
        TrieNode* children[26];
        bool end;
    }* root;
    
    int minimumLengthEncoding(vector<string>& words) {
        root = new TrieNode();
        int n = words.size();
        
        for(int i = 0; i < n; i++){
            insert(string(words[i].rbegin(), words[i].rend()), i);
        }
        
        int ans = 0;
        
        dfs(root, 0, ans);
        
        return ans;
    }
    
    void dfs(TrieNode *curr, int len, int &ans){
        bool leaf = true;
        
        for(int i = 0; i < 26; i++) {
            if(curr->children[i] != NULL) {
                dfs(curr->children[i], len + 1, ans);
                leaf = false;
            }
        }
        
        if(leaf)
            ans += len + 1;
    }
    
    void insert(string s, int idx){
        auto curr = root;
        
        for(char &c: s) {
            int id = c - 'a';
            
            if(curr->children[id] == NULL)
                curr->children[id] = new TrieNode();
            
            curr = curr->children[id];
        }
        
        curr->end = true;
    }
};
