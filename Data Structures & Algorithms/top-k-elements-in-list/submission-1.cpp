class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>hash;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }
        vector<vector<int>>bucket(n+1);
        for(auto h:hash)
        {
            bucket[h.second].push_back(h.first);
        }
        
        for(int i=n;i>=0;i--)
        {
            if(!bucket[i].empty())
            {
                for(auto b:bucket[i])
                {
                    if(k==0) return ans;
                    k--;
                    ans.push_back(b);

                }
            }

        }
        return ans;
        
    }
};
