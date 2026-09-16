class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!ans.empty() && ans.back()==nums[i]) continue;
            ans.push_back(nums[i]);
        }
        int m=ans.size();
        for(int i=0;i<m;i++)
        {
            nums[i]=ans[i];
        }
        return ans.size();
        
    }
};