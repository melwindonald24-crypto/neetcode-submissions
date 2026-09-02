class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n=coins.size();    
         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
        
    }
    int helper(int i,int tar,vector<int>& coins,vector<vector<int>>&dp)
    {
        if(tar==0)
        {
            return 1;
        }
        if(i==0)
        {
            return (tar%coins[0])==0;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];

        int notTake=helper(i-1,tar,coins,dp);
        int take=0;
        if(coins[i]<=tar)
        {
            take=helper(i,tar-coins[i],coins,dp);
        }
        return dp[i][tar]=take+notTake;
    }
};
