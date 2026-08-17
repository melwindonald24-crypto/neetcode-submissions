class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int k=0;k<n-2;k++)
        {
            int i=k+1,j=n-1;
           while(i<j)
           {
            if(nums[i]+nums[j]+nums[k]==0)
            {
                
                st.insert({nums[i],nums[j],nums[k]});
                i++;
                j--;
            }
            else if(nums[i]+nums[j]+nums[k]>0)
            {
                j--;
            }
            else
            {
                i++;
            }
           }

        }
        for(auto s:st)
        {
            ans.push_back(s);
        }
        return ans;
        
    }
};
