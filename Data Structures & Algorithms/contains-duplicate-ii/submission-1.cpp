class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<int,int>mpp;
        int nearby=false;
        for(int i=0;i<n;i++)
        {
            if(mpp.find(nums[i])!=mpp.end())
            {
                int j=mpp[nums[i]];
                if(abs(i-j)<=k)
                {
                    nearby=true;
                }
                
            }
            
            mpp[nums[i]]=i;
        }
        return nearby;

        
    }
};