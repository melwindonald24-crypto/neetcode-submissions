class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,helperDFS_DP(i,j,matrix,dp));
            }
        }
        return maxi;
        
    }
    int helperDFS_DP(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=0) return dp[i][j];

        int ans=1;

        if(i+1<matrix.size() && matrix[i][j]>matrix[i+1][j])
        {
            ans=max(ans,1+helperDFS_DP(i+1,j,matrix,dp));
        }
        if(i-1>=0 && matrix[i][j]>matrix[i-1][j])
        {
            ans=max(ans,1+helperDFS_DP(i-1,j,matrix,dp));
        }
         if(j+1<matrix[0].size() && matrix[i][j]>matrix[i][j+1])
        {
            ans=max(ans,1+helperDFS_DP(i,j+1,matrix,dp));
        }
        if(j-1>=0 && matrix[i][j]>matrix[i][j-1])
        {
            ans=max(ans,1+helperDFS_DP(i,j-1,matrix,dp));
        }
        return dp[i][j]=ans;
        
    }
};
