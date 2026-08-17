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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        queue<TreeNode*>p_st;
        queue<TreeNode*>q_st;
        TreeNode*temp=root;
        while(temp)
        {
            p_st.push(temp);
            if(temp==p) break;
            if(p->val>temp->val)
            {
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }
        temp=root;
        while(temp)
        {
            q_st.push(temp);
            if(temp==q) break;
            if(q->val>temp->val)
            {
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }
        TreeNode*ans=NULL;
        while(!p_st.empty() && !q_st.empty() && p_st.front()==q_st.front())
        {
            ans=p_st.front();
            p_st.pop();
            q_st.pop();

        }
        return ans;

        
    }
};
