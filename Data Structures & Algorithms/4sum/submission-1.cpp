class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int k=j+1,m=n-1;
                while(k<m)
                {
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[m];
                    if(sum==target)
                    {
                        st.insert({nums[i],nums[j],nums[k],nums[m]});
                        k++;
                        m--;
                    }
                    else if(sum>target)
                    {
                        m--;
                    }
                    else{
                        k++;
                    }

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