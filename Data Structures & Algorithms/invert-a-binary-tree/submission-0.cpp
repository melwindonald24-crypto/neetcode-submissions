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
    TreeNode* invertTree(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL) return NULL;

        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
          
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

            TreeNode*t=temp->left;
            temp->left=temp->right;
            temp->right=t;
        }
        return root;

        
    }
};
