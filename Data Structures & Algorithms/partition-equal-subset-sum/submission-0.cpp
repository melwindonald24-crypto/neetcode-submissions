class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
         int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
     
        return subsetSumK(n-1,k,nums,dp);
       

    }
    bool subsetSumK(int n,int k,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(k==0) return true;
        if(n==0){
            return nums[n]==k;
        }

        if(dp[n][k]!=-1)
        {
            return dp[n][k];
        }
        bool notTake=subsetSumK(n-1,k,nums,dp);
        bool take=false;
        if(nums[n]<=k)
        {
            take=subsetSumK(n-1,k-nums[n],nums,dp) ;
        }
        return dp[n][k]= take || notTake;
    }
};
