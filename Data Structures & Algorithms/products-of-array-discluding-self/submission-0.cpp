class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prd=1,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
            count++;
            continue;
            } 
            prd*=nums[i];
            

        }
        vector<int>ans(nums.size(),0);
        if(count>1) return ans;
        for(int i=0;i<nums.size();i++)
        {
            if(count==1)
            {
                ans[i]=(nums[i]==0?prd:0);
            }
            else
            {
                ans[i]=(prd/nums[i]);
            }
        
            
        }
        return ans;

    }
};
