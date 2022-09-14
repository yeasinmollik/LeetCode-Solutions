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
    int ans = 0;
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt[10] = {};
        cnt[root->val]++;
        solve(root, cnt);
        return ans;
    }
    
    void solve(TreeNode* root, int cnt[]){
        if(!root->left && !root->right){
            int odd = 0;
            for(int i = 1; i <= 9; i++){
                odd += cnt[i]&1;
            }
            ans += odd < 2;
        }
        
        if(root->left){
            cnt[root->left->val]++;
            solve(root->left, cnt);
            cnt[root->left->val]--;
        }
        if(root->right){
            cnt[root->right->val]++;
            solve(root->right, cnt);
            cnt[root->right->val]--;
        }
    }
};