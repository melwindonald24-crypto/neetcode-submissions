class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int>mpp;
        int n=s.size();
        if(n==0) return 0;

        int i=0;
        mpp.insert({s[0],0});
        int max_len=1;
        for(int j=1;j<n;j++)
        {
            if(mpp.find(s[j])==mpp.end())
            {
                mpp.insert({s[j],j});
                max_len=max(max_len,j-i+1);
            }
            else
            {
                
                i=max(i,mpp[s[j]]+1);
                max_len=max(max_len,j-i+1);
                mpp[s[j]]=j;
            }

        }

        return max_len;
    }
};
