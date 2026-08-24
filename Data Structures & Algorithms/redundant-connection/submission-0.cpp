class Disjointset{
    vector<int>parent;
    vector<int>rank;
public:

    Disjointset(int n)
    {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<n+1;i++)
        {
            parent[i]=i;
        }
    }
    int find(int u)
    {
        if(u==parent[u]) return u;

        return parent[u]=find(parent[u]);
    }
    bool unionFind(int u,int v)
    {
        int a=find(u),b=find(v);
        if(a==b)
        {
            return false;
        }
        if(rank[a]>rank[b])
        {
            parent[b]=a;
        }
        else if(rank[a]<rank[b])
        {
            parent[a]=b;
        }
        else{
            parent[a]=b;
            rank[b]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();
        vector<int>ans;
        Disjointset*dj=new Disjointset(n);
        
        
        for(int i=0;i<n;i++)
        {
            if(!dj->unionFind(edges[i][0],edges[i][1]))
            {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }

        }
        return ans;
       
    
    }

   
};
