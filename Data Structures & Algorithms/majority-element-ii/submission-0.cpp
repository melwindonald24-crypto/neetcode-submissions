class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int,int>mpp;
        int n=nums.size();
        int tar=n/3;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(mpp.find(nums[i])!=mpp.end() && mpp[nums[i]]==INT_MIN) continue;
            
            mpp[nums[i]]++;
            if(mpp[nums[i]]>tar)
            {
                mpp[nums[i]]=INT_MIN;
                ans.push_back(nums[i]);
            }
        }
        return ans;
        
    }
};