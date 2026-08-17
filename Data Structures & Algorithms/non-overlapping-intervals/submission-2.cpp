class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {

         int n=inter.size();
         vector<vector<int>>nonOver;

         sort(inter.begin(),inter.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
         });
         
         nonOver.push_back(inter[0]);
         for(int i=1;i<n;i++)
         {
            if(inter[i][0]>=nonOver[nonOver.size()-1][1])
            {
                nonOver.push_back(inter[i]);
            }
         }
         return inter.size()-nonOver.size();
        
    }
};
