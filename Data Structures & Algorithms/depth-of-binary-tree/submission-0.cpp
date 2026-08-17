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
    int maxDepth(TreeNode* root) {

        int maxD=0;
        calcmaxD(root,0,maxD);
        return maxD;

    }
    void calcmaxD(TreeNode*root,int len,int &maxD)
    {
        if(root){
        maxD=max(len,maxD);
        calcmaxD(root->left,++len,maxD);
        calcmaxD(root->right,++len,maxD);
        }
    }
};
