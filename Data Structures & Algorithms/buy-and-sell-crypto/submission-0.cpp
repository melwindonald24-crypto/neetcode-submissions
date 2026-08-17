class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max_profit=INT_MIN;
        int min_price=INT_MAX;
        for(int i=1;i<prices.size();i++)
        {
            max_profit=max(max_profit,prices[i]-min_price);
            min_price=min(min_price,prices[i]);
            
        }
        return max_profit<0?0:max_profit;
        
    }
};
