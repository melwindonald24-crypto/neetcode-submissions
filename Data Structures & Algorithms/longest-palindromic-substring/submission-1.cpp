class Solution {
public:
    string longestPalindrome(string s) {

        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int max_i=0;
        int max_len=0;
        if(n==1) return s;

        for(int len=1;len<n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j=i+len-1;;
                if(s[i]==s[j])
                {
                    if(j-i<=2)
                    {
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];

                    }
                }
                if(dp[i][j] && j-i+1>max_len)
                {
                        max_i=i;
                        max_len=j-i+1;
                }

            }
        }
        return s.substr(max_i,max_len);


        
        
    }
};
