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
    int sum = 0;
    
    int sumEvenGrandparent(TreeNode* root) {
        calc(root, 1, false, false);
        return sum;
    }
    
    void calc(TreeNode* curr, int level, bool dad, bool grandpa){
        if(curr == NULL)
            return;
        
        if(level > 2 && grandpa)
            sum += curr->val;
        
        grandpa = dad;
        dad = (curr->val % 2 == 0);
        
        calc(curr->left, level + 1, dad, grandpa);
        calc(curr->right, level + 1, dad, grandpa);
    }
};