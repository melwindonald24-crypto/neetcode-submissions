class Solution {
public:

    string encode(vector<string>& str) {
        string key="";
        for(int i=0;i<str.size();i++)
        {
            key+=to_string(str[i].size())+'#'+str[i];
        }
        return key;

    }

    vector<string> decode(string s) {
        vector<string>ans;
        int k=0;
        while(k<s.size())
        {
            string key="";
            string len="";
            while(isdigit(s[k]))
            {
                len+=s[k++];
            }
            k++;
            int iter=stoi(len);
            while(iter--)
            {
                key+=s[k++];
            }
            ans.push_back(key);
         
        }
        return ans;

    }
};
