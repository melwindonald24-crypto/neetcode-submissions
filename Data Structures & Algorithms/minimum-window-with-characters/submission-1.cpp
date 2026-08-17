class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size()<t.size()) return "";
        
        vector<int>hash(256,0);
       

        for(auto c:t)
        {
            hash[c]++;
        }
        int cnt=0;
        int n=s.size();
        int m=t.size();
        int l=0,r=0,start=0;
        int min_len=INT_MAX;
        
        if(n==1 && s[1]!=t[1]) return "";

        while(r<n)
        {
            if(cnt<m)
            {
                
                if(hash[s[r]]>0) cnt++; 
                hash[s[r]]--; 
                r++;
            }
            else
            {
                if(min_len>r-l)
                {
                    start=l;
                    min_len=r-l;

                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
        }
        while(cnt==m)
        {
            if(min_len>r-l)
                {
                    start=l;
                    min_len=r-l;

                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;

        }
        return s.substr(start,min_len);


        
    }
};
