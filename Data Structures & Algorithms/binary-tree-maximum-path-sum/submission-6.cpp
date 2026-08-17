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
        max_path=max(calcMaxPath(root,max_path),max_path);
        return max_path;
    }    

    int calcMaxPath(TreeNode*root,int &max_path)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=max(0,(calcMaxPath(root->left,max_path)));
        int right=max(0,(calcMaxPath(root->right,max_path)));
        max_path=max(left+right+root->val,max_path);
        return max(left+root->val,right+root->val);
    }

};
