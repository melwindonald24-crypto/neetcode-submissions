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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        return buildTreeHelper(preorder,inorder,i);
        
    }
    TreeNode* buildTreeHelper(vector<int> &preorder,vector<int> &inorder,int &i)
    {
        if(inorder.empty()) return NULL;

        int root=preorder[i++];
        TreeNode*node=new TreeNode(root);
        int partition=split(inorder,root);
        vector<int>leftsub;
        vector<int>rightsub;
        for(int j=0;j<partition;j++)
        {
            leftsub.push_back(inorder[j]);
        }
        for(int j=partition+1;j<inorder.size();j++)
        {
            rightsub.push_back(inorder[j]);
        }
        node->left=buildTreeHelper(preorder,leftsub,i);
        node->right=buildTreeHelper(preorder,rightsub,i);

        return node;

    }
    int split(vector<int>&inorder,int ele)
    {
        
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==ele)
            {
                return i;
            }
        }
        return -1;
       
    }
};
