class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>hash;
     
        for(int i=0;i<strs.size();i++)
        {
            vector<int> count(26,0);

            
            for(int j=0;j<strs[i].size();j++)
            {
                count[strs[i][j]-'a']++;
            }
            string key="";
            for(auto c:count)
            {
                key+=(c==0?"#":to_string(c));
            }
            hash[key].push_back(strs[i]);   
        }
        for(auto h:hash)
        {
            ans.push_back(h.second);
        }
        return ans;
    }
};
