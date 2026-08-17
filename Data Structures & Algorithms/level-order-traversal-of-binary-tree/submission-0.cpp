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

        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int level=temp.second;
            if(temp.first->left) q.push({temp.first->left,level+1});
            if(temp.first->right) q.push({temp.first->right,level+1});
            if(level == ans.size()) ans.push_back({});
            ans[level].push_back(temp.first->val);

        }
        return ans;
        
    }
};
