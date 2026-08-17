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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        if(!root) return "";
        string ans=to_string(root->val)+"#";
        

        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
          
            if(temp->left) 
            {
                q.push(temp->left);
                ans+=to_string(temp->left->val)+"#";
            }
            else{
                ans+="N#";
            }
           
            if(temp->right) 
            {
                q.push(temp->right);
                ans+=to_string(temp->right->val)+"#";

            }
            else
            {
                ans+="N#"  ;
            }
        }
        return ans;    
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<int>arr;
        int i=0;
        if(data=="") return NULL;
        while(i<data.size())
        {
            string num="";
            while(data[i]!='#')
            {
                num+=data[i++];
            }
            if(num=="N")
            {
                arr.push_back(INT_MIN);
            }
            else
            {
                arr.push_back(stoi(num));
            }
            i++;
        }
        queue<TreeNode*> q;
        i=1;
        TreeNode*root=new TreeNode(arr[0]);
        q.push(root);

        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            
            if(arr[i]!=INT_MIN) 
            {
                temp->left=new TreeNode(arr[i++]);
                q.push(temp->left);
            }
            else{
                temp->left=NULL;
                i++;
            }
            if(arr[i]!=INT_MIN) 
            {
                temp->right=new TreeNode(arr[i++]);
                q.push(temp->right);
            }
            else{
                temp->right=NULL;
                i++;
            }
        }
        return root;
    }
    
};
