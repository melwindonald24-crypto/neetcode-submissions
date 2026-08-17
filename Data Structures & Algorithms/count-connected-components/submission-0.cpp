class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }    

            unordered_set<int>st;
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(st.find(i)==st.end())
                {
                    count++;
                    DFS(adj,st,-1,i);

                }

            }
            return count;
    }    


        void DFS(vector<vector<int>>&adj,unordered_set<int>&st,int par,int i)
        {
            if(st.find(i)!=st.end() || i==par)
            {
                return ;
            }
            st.insert(i);
            for(int j=0;j<adj[i].size();j++)
            {
                DFS(adj,st,i,adj[i][j]) ;

            }

        }

    
};
