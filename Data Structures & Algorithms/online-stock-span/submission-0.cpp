class StockSpanner {
public:
   
   stack<pair<int,int>>activeSt;

    StockSpanner() {
        
    }
    
    int next(int price) {

        int count=1;
      while(!activeSt.empty() && activeSt.top().first<=price)
      {
        count+=activeSt.top().second;
        activeSt.pop();

      }
      activeSt.push({price,count});
       
        return count;    
  
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */