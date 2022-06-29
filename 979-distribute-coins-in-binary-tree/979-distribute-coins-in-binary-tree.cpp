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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        getMoves(root, moves);
        return moves;
    }
    
    int getMoves(TreeNode* root, int &moves){
        if(root == NULL)
            return 0;
        
        int left = getMoves(root->left, moves);
        int right = getMoves(root->right, moves);
        
        moves += abs(left) + abs(right);
        return (root->val - 1) + left + right;
    }
};