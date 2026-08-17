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
        queue<pair<TreeNode*,vector<int>>>q;
        q.push({root,{root->val}});
        int maxi=INT_MIN;

        while(!q.empty())
        {
            auto temp=q.front();
            TreeNode*node=temp.first;
            auto paths=temp.second;
            q.pop();
          
            if(node->left) 
            {
                vector<int>leftChild;
                for(auto path:paths)
                {
                    leftChild.push_back(path+node->left->val);
                    maxi=max(maxi,path+node->left->val);
                }   
                q.push({node->left,leftChild});
            }
            if(node->right) 
            {
                vector<int>rightChild;
                for(auto path:paths)
                {
                    rightChild.push_back(path+node->right->val);
                    maxi=max(maxi,path+node->right->val);
                }   
                q.push({node->right,rightChild});
            }
            if(node->left&& node->right)
            {
                auto temp1=q.front();
                q.pop();
                auto temp2=q.front();
                q.pop();
                temp1.second.push_back(node->val+node->left->val+node->right->val);
                q.push(temp1);
                temp2.second.push_back(node->val+node->left->val+node->right->val);
                q.push(temp2);
                maxi=max(maxi,node->val+node->left->val+node->right->val);   

            }

        }
        return maxi;
        

    }    

};
