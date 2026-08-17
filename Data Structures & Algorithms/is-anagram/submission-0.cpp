class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(256,0);
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }
        for(auto val:hash)
        {
            if(val!=0) return false;
        }
        return true;
        
    }
};
