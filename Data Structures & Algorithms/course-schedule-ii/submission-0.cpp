class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {


        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
     

        vector<int> ans;
        queue<int>q;
         for(int i=0;i<n;i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }


        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            indegree[i]=-1;
            ans.push_back(i);
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]--;
                if(indegree[adj[i][j]]==0)
                {
                    q.push(adj[i][j]);
                }
            }
         
        }
        
        return ans.size()==n?ans:vector<int>{};
        
    }
};
