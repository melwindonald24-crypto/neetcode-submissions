class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {

        int n=inter.size();
        sort(inter.begin(),inter.end());
        vector<vector<int>> ans;
        ans.push_back(inter[0]);

        for(int i=1;i<n;i++)
        {
            if(inter[i][0]<=ans[ans.size()-1][1])
            {
                ans[ans.size()-1]={min(inter[i][0],ans[ans.size()-1][0]),
                max(inter[i][1],ans[ans.size()-1][1])};
            }
            else{
                ans.push_back(inter[i]);
            }

        }
        return ans;
         
        
    }
};
