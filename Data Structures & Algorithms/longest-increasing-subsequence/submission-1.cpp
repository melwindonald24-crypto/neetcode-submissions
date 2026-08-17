class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            maxi=max(dp[i],maxi);
            
        }
        return maxi;
        
    }
};
