class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //vector<int>dp(n+1,0);
        int first=0,second=0;
        int curr;
        for(int i=2;i<n+1;i++)
        {
            curr=min(second+cost[i-1],first+cost[i-2]);
            first=second;
            second=curr;
        }
        return curr;

    }
};
