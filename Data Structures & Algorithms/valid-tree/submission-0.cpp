

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);
        if(edges.empty()) return true;
        if(edges.size()!=n-1) return false;

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int>st;
        bool isLoop=checkLoop(adj,-1,st,0);
        if(!isLoop && n==st.size()) return true;
        return false;

    }
    bool checkLoop(vector<vector<int>> &adj,int par,unordered_set<int>&st,int i)
    {
        if(st.find(i)!=st.end())
        {
            return true;
        }
        st.insert(i);
        for(int j=0;j<adj[i].size();j++)
        {
            if(adj[i][j]!=par)
            {
             if(checkLoop(adj,i,st,adj[i][j])) return true;
            }
        }
        return false;


    }
};
