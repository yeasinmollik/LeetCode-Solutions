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
    int n;
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        n = nums.size();
        return getBST(0, n-1, nums);
    }
    
    TreeNode* getBST(int l, int r, vector<int>& nums){
        if(l > r)
            return NULL;
        
        int mid = (l + r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = getBST(l, mid - 1, nums);
        root->right = getBST(mid + 1, r, nums);
        return root;
    }
};