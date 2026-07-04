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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(res.size()<cur.second){
                res.push_back({});
            }
            res[cur.second-1].push_back(cur.first->val);
            if(cur.first->left) q.push({cur.first->left,cur.second + 1});
            if(cur.first->right) q.push({cur.first->right,cur.second + 1});
        }
        return res;
    }
};
