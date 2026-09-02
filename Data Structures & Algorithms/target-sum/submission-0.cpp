class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n=nums.size();
        map<pair<int,int>,int>dp;
        return helper(n-1,target,nums,dp);
    }
    int helper(int i,int tar,vector<int>& nums,map<pair<int,int>,int>&dp)
    {
        if(i==0)
        {
                if(nums[0] == 0 && tar == 0)
                     return 2;

            return (tar-nums[0]==0 || tar+nums[0]==0)?1:0;
        }
        if(dp.find({i,tar})!=dp.end()) return dp[{i,tar}];

        int plus=helper(i-1,tar-nums[i],nums,dp);
        int minus=helper(i-1,tar+nums[i],nums,dp);
        return dp[{i,tar}]=plus+minus;
    }
};
