class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
         this->k=k;
        for(auto n:nums)
        {
            heap.push(n);
            if(heap.size()>k)
            {
                heap.pop();
            }

        }
        
    }
    
    int add(int val) {

        heap.push(val);
        if(heap.size()>k)
        {
            heap.pop();
        }
        
        return heap.top();
        
    }
};
