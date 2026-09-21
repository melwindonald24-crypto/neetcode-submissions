class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {

        int i=0,j=0;
        int n=nums.size();
        int sum=0,mini=INT_MAX;
        while(i<n && j<n)
        {
            sum+=nums[j];
            while(i<=j && sum>=tar)
            {

                mini=min(j-i+1,mini);
                sum-=nums[i];
                i++;
                
            }
            
            j++;
            
        }
        return mini==INT_MAX?0:mini;
        
    }
};