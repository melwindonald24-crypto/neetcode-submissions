class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>hash;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;

        }
        for(auto h:hash)
        {
             if(h.second>=k)
            {
                ans.push_back(h.first);
            }
        }
        return ans;
        
    }
};
