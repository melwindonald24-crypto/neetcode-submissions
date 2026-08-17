class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int>need(26,INT_MIN);
        vector<int>present(26,0);

        int n=s2.size();
        int m=s1.size();
        if(m > n) return false;

        for(auto it:s1)
        {
            if(need[it-'a']==INT_MIN){
                need[it-'a']=1;
            }
            else{
                need[it-'a']++;
            }
        }
        int k=m;
        int count=0;

        for(int i=0;i<k;i++)
        {
            present[s2[i]-'a']++;
            if(present[s2[i]-'a']<=need[s2[i]-'a'])
            {
                count++;
            }

        }
        if(count==m) return true;


        for(int i=1;i<=n-k;i++)
        {
            present[s2[i-1]-'a']--;
            
            if(present[s2[i-1]-'a']<need[s2[i-1]-'a'])
            {
                count--;
            }
            
            present[s2[k+i-1]-'a']++;
            if(present[s2[k+i-1]-'a']<=need[s2[k+i-1]-'a'])
            {
                count++;
            }
            if(count==m) return true;

        }
        return false;
    }
};
