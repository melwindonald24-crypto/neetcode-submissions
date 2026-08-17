class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        if(text1.size()>text2.size())
        {
            return longestCommonSubsequence(text2,text1);
        }
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int max_len=0;

        for(int i=0;i<1;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(text2[j]==text1[i])
                {
                    dp[i][j]=1;
                    max_len=max(max_len,dp[i][j]);
                }
                
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(text2[j]==text1[i])
                {
                    for(int ki=i-1;ki>=0;ki--)
                    {
                        for(int kj=j-1;kj>=0;kj--)
                        {
                            dp[i][j]=max(dp[ki][kj]+1,dp[i][j]);
                            max_len=max(max_len,dp[i][j]); 
                        }
                    }
                }
            }
        }
        return max_len;
        
    }
};
