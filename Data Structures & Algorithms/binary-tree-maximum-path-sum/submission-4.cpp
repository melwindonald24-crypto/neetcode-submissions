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
    int maxPathSum(TreeNode* root) {
        
        int max_path=root->val;
        calcMaxPath(root,max_path);
        return max_path;
    }    

    int calcMaxPath(TreeNode*root,int &max_path)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=(calcMaxPath(root->left,max_path));
        int right=(calcMaxPath(root->right,max_path));
        max_path=max(left+right+root->val,max_path);
        return max(left+root->val,right+root->val);
    }

};
