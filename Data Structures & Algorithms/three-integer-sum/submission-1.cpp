class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
      
        for(int k=0;k<n-2;k++)
        {
            int i=k+1,j=n-1;
            if(k>0 && nums[k]==nums[k-1]) continue;

           while(i<j)
           {
            if(nums[i]+nums[j]+nums[k]==0)
            {
                
                ans.push_back({nums[i],nums[j],nums[k]});

                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                
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
      
        return ans;
        
    }
};
