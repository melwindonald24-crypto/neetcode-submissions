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
    bool isValidBST(TreeNode* root) {

        queue<pair<TreeNode*,pair<int,int>>>q;//min,max
        q.push({root,{INT_MIN,INT_MAX}});
        while(!q.empty())
        {
            auto temp=q.front();
            TreeNode*node=temp.first;
            auto range=temp.second;
            int min_range=range.first;
            int max_range=range.second;

            q.pop();

            if(node->left)
            {
                if(node->left->val<min_range || node->left->val>node->val)
                {
                    return false;
                }
                q.push({node->left,{min_range,node->val}});
            }
            if(node->right)
            {
                if(node->right->val<node->val || node->right->val>max_range)
                {
                    return false;
                }
                q.push({node->right,{node->val,max_range}});
            }

        }
        return true;
        

    }
};
