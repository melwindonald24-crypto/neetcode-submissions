class Solution {
public:
    bool canFinish(int numCourse, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourse, vector<int>(numCourse, 0));
        for(int i=0;i<prerequisites.size();i++)
        {
                adj[prerequisites[i][1]][prerequisites[i][0]]=1;
        }
        vector<int>indegree(numCourse,0);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[i]+=adj[j][i];
            }
        }
        bool isProcessing=false;
        while(true)
        {
            int del=-1;
            for(int i=0;i<indegree.size();i++)
            {
                if(indegree[i]==0)
                {
                    indegree[i]=-1;
                    isProcessing=true;
                    del=i;
                    break;
                }
            }
            if(!isProcessing) break;
            for(int i=0;i<adj.size();i++)
            {
                if(adj[del][i]==1)
                {
                    indegree[i]--;
                }
            }
            isProcessing=false;

        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]!=-1)
            {
                return false;
            }
        }
        return true;

    } 
       
};
