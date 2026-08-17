class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;
        unordered_map<int,int>hash;
     
        for(int i=0;i<strs.size();i++)
        {
            int h=0;
            for(int j=0;j<strs[i].size();j++)
            {
                h+=((int)(strs[i][j]*strs[i][j]));
            }
            if(hash.find(h)!=hash.end())
            {
                ans[hash.find(h)->second].push_back(strs[i]);
                continue;
            }
            ans.push_back({strs[i]});
            hash[h]=ans.size()-1;
        }
        return ans;
    }
};
