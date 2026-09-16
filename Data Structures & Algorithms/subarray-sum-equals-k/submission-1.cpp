class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int n=nums.size(),sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int diff=sum-k;

            if(mpp.find(diff)!=mpp.end())
            {
                count+=mpp[diff];
            }
            mpp[sum]++;
            
        }
        return count;
        
       
    }
};