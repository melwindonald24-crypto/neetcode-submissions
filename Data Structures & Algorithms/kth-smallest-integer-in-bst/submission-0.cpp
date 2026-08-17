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
    int kthSmallest(TreeNode* root, int k) {

        if(!root) return 0;

        TreeNode*res=kthSmallFinder(root,k);
    
        return res->val;
        
    }
    TreeNode* kthSmallFinder(TreeNode*root,int &k)
    {
        if(root)
        {
            TreeNode*left=kthSmallFinder(root->left,k);
            if(left) return left;
            k--;
            if(k==0) return root;
            TreeNode*right=kthSmallFinder(root->right,k);
            if(right) return right;
        }
        return NULL;
        
    }
};
