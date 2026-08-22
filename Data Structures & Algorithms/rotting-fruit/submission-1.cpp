class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
      

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
        
                }
            }
        }
        int count=0;
        
        while(!q.empty())
        {
            int size=q.size();
            bool rotted=false;
            
            for(int k=0;k<size;k++)
            {
                auto top=q.front();
                int i=top.first,j=top.second;
                q.pop();
                if(BFS(grid,q,i+1,j))rotted=true;
                if(BFS(grid,q,i-1,j))rotted=true;
                if(BFS(grid,q,i,j+1))rotted=true;
                if(BFS(grid,q,i,j-1))rotted=true;
                
            }
            if(rotted) count++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return count;
        
    }
    bool BFS(vector<vector<int>>& grid,queue<pair<int,int>>&q,
        int i,int j)
    {
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || 
        grid[i][j]==0 || grid[i][j]==2)
        {
            return false;
        }
        grid[i][j]=2;
        q.push({i,j});
        return true;
   
    }
};
