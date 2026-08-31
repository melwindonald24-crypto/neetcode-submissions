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
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));

        for(int i=0;i<n;i++) dp[i][0]=true;
        dp[1][nums[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int tar=1;tar<=k;tar++)
            {
                bool notTake=dp[i-1][tar];
                bool take=false;
                if(nums[i]<=tar)
                {
                    take=dp[i-1][tar-nums[i]];
                }
                dp[i][tar]= take || notTake;
            }
        }
        return dp[n-1][k];
     
       
       

    }
    // bool subsetSumK(int n,int k,vector<int>&nums,vector<vector<int>>&dp)
    // {
    //     if(k==0) return true;
    //     if(n==0){
    //         return nums[n]==k;
    //     }

    //     if(dp[n][k]!=-1)
    //     {
    //         return dp[n][k];
    //     }
    //     bool notTake=subsetSumK(n-1,k,nums,dp);
    //     bool take=false;
    //     if(nums[n]<=k)
    //     {
    //         take=subsetSumK(n-1,k-nums[n],nums,dp) ;
    //     }
    //     return dp[n][k]= take || notTake;
    // }
};
