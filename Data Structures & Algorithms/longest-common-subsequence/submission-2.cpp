class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        if(text1.size()>text2.size())
        {
            return longestCommonSubsequence(text2,text1);
        }
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int max_len=0;

        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                max_len=max(dp[i][j],max_len);
               
            }
        }
        return max_len;
        
    }
};
