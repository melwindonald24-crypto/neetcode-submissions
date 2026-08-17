class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        // vector<int>dp(n,0);
        // dp[0]=nums[0];
        int currMax=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++)
        {
            currMax=max(currMax+nums[i],nums[i]);
            maxi=max(maxi,currMax);
        }
        return maxi;

    }
};
