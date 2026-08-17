class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n=nums.size();
        //vector<int>dp_max(n,-1);
       //vector<int>dp_min(n,-1);
        int dp_max=nums[0];
        int dp_min=nums[0];
        int maxi=dp_max;

        for(int i=1;i<n;i++)
        {
            dp_max=max(dp_max*nums[i],max(dp_min*nums[i],nums[i]));
            dp_min=min(dp_max*nums[i],min(dp_min*nums[i],nums[i]));

            maxi=max(dp_max,maxi);
        }
        return maxi;
        
    }
};
