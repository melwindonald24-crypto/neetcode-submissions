class Solution {
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        if(n==1) return dp[0];
        dp[1]=max(nums[0],nums[1]);
        if(n==2) return 0;

        for(int i=2;i<n-1;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        int maxFirst=dp[n-2];

        dp[1]=nums[1];
        dp[2]=max(dp[1],nums[2]);
        for(int i=3;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return max(maxFirst,dp[n-1]);

        
        
    }
};
