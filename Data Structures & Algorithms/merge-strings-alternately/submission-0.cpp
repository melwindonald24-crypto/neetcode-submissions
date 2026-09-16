class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        bool left=true;
        int i=0,j=0;
        int n=word1.size(),m=word2.size();
        string ans="";
        while(i<n && j<m)
        {
            left?ans+=word1[i++]:ans+=word2[j++];
            left=left?false:true;

        }
        while(i<n) ans+=word1[i++];
        while(j<m) ans+=word2[j++];
        return ans;        
    }
};