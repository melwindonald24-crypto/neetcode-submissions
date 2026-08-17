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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        queue<TreeNode*>q;
        q.push(root);
        
        TreeNode*temp2=subRoot;

        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
          
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

            if(temp->val==temp2->val)
            {
                if(checkSame(temp,temp2))
                {
                    return true;
                }

            }
        }
        return false;
        
    }
    bool checkSame(TreeNode*root1,TreeNode*root2)
    {
        if(root1 && root2)
        {
            if(root1->val!=root2->val)
            {
                return false;
            }
            return checkSame(root1->left,root2->left)&&checkSame(root1->right,root2->right);
        }
        else{
            if(root1==NULL && root2==NULL)
            {
                return true;
            }else{
                return false;
            }
        }
    }
};
