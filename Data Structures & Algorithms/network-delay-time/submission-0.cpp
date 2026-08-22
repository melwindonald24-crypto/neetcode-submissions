class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        
        }
        dist[k]=0;
        pq.push({0,k});
   
        int min_weight=0;
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int i=top.second;
            int weight=top.first;
           
            for(int j=0;j<adj[i].size();j++)
            {
                if(adj[i][j].second+weight<dist[adj[i][j].first])
                {
                    dist[adj[i][j].first]=adj[i][j].second+weight;
                    pq.push({adj[i][j].second+weight,adj[i][j].first});
                     
                }
            }

           
        }
        for(int i=1;i<dist.size();i++)
        {
            if(dist[i]==INT_MAX)
            {
                return -1;
            }
            min_weight=max(min_weight,dist[i]);
        }
        return min_weight;
        
    }
};
