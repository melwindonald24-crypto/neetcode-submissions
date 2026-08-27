class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        int mini=INT_MAX;
        dfs(adj,src,dst,mini,k,0,0);
        return mini==INT_MAX?-1:mini;
        
    }
    void dfs(vector<vector<pair<int,int>>>&adj, int src, int dst, int &mini
    ,int k,int count,int sum)
    {
        if(sum >= mini) return;
        if(count>k+1) return ;
        if(src==dst && count<=k+1)
        {
            mini=min(sum,mini);
            return;
        }
        for(int i=0;i<adj[src].size();i++)
        {
            dfs(adj,adj[src][i].first,dst,mini,k,count+1,sum+adj[src][i].second);
        }

    }
};
