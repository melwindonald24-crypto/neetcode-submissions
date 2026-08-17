class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n)
        {
            if(newInterval[1]<intervals[i][0])
            {
                ans.push_back(newInterval);
                for(int j=i;j<n;j++)
                {
                    ans.push_back(intervals[j]);
                }
                return ans;
            }
            else
            {
                if(newInterval[1]<=intervals[i][1] || 
                newInterval[1]>=intervals[i][1] && 
                newInterval[0]<=intervals[i][1])
                {
                    newInterval={min(newInterval[0],intervals[i][0]),
                    max(newInterval[1],intervals[i][1])};
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
            i++;
        }
        ans.push_back(newInterval);
        return ans;
        
    }
};
