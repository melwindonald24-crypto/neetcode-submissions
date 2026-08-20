class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_area=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int maxi=0;
                if(grid[i][j]==1)
                {
                    destroyIsland(grid,i,j,maxi);
                    max_area=max(max_area,maxi);
                }
            }
        }
        return max_area;

        
    }

    void destroyIsland(vector<vector<int>>& grid,int i,int j,int &maxi)
    {
        if(i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        {
            return;
        }
        grid[i][j]=0;
        maxi+=1;
        destroyIsland(grid,i,j+1,maxi);
        destroyIsland(grid,i,j-1,maxi);
        destroyIsland(grid,i+1,j,maxi);
        destroyIsland(grid,i-1,j,maxi);


    }
};
