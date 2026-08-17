class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp_max(n,-1);
        vector<int>dp_min(n,-1);
        dp_max[0]=nums[0];
        dp_min[0]=nums[0];
        int maxi=dp_max[0];

        for(int i=1;i<n;i++)
        {
            dp_max[i]=max(dp_max[i-1]*nums[i],max(dp_min[i-1]*nums[i],nums[i]));
            dp_min[i]=min(dp_max[i-1]*nums[i],min(dp_min[i-1]*nums[i],nums[i]));

            maxi=max(dp_max[i],maxi);
        }
        return maxi;
        
    }
};
