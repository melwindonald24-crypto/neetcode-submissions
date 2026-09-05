class Solution {
public:
    int numDistinct(string s, string t) {

        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,s,t,dp);  
    }

    int helper(int i,int j,string&s,string&t,vector<vector<int>>&dp)
    {
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j])
        {
            ans=helper(i+1,j+1,s,t,dp)+helper(i+1,j,s,t,dp);
        }
        else ans=helper(i+1,j,s,t,dp);

        return dp[i][j]=ans;
    }
};
