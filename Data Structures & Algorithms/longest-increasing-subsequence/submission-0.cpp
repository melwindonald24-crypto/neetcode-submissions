class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp(n,-1);
        int maxi=1;
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                dp[i]=dp[i-1]+1;
            }
            else
            {
                dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
        
    }
};
