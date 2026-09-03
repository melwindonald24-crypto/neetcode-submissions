class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size()) return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int decision=helper(0,0,s1,s2,s3,dp);
        return decision==0?false:true;
 
    }
    int helper(int i,int j,string &s1, string &s2, string &s3,
    vector<vector<int>>&dp)
    {
        if(i==s1.size() && j==s2.size())
        {
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(i<s1.size() && s1[i]==s3[i+j])
        {
            ans=helper(i+1,j,s1,s2,s3,dp);
        }
        if(j<s2.size() && s2[j]==s3[i+j])
        {
            ans=ans || helper(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j]=ans;
        
    }
};
