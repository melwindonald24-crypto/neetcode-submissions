class Solution {
public:
    int minDistance(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,word1,word2,dp);
    }

    int helper(int i,int j,string& w1,string &w2,vector<vector<int>>&dp)
    {
        if(j==w2.size()) return w1.size()-i;
        if(i==w1.size()) return w2.size()-j;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans;
        if(w1[i]==w2[j])
        {
            ans=helper(i+1,j+1,w1,w2,dp);
        }
        else{
            ans=min(helper(i+1,j+1,w1,w2,dp)+1,min(helper(i+1,j,w1,w2,dp)+1,
            helper(i,j+1,w1,w2,dp)+1));
        }
        return dp[i][j]=ans;
    }
};
