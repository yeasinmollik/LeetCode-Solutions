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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        vector<double> ans;
        double sum = -1, cnt = -1, lastLevel = -1;
        while(!q.empty()){
            auto[level, node] = q.front();
            q.pop();
            
            if(level!=lastLevel){
                ans.emplace_back(sum / cnt);
                cnt = 0, sum = 0;
            }
            cnt++, sum += node->val, lastLevel = level;
            
            if(node->left)
                q.push({level + 1, node->left});
            if(node->right)
                q.push({level + 1, node->right});
        }
        ans.emplace_back(sum/cnt);
        return vector<double>(ans.begin() + 1, ans.end());
    }
};