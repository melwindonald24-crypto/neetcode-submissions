class MinStack {
public:
    stack<pair<int,int>>st;

    MinStack() {
    }
    
    void push(int val) {
        if(!st.empty())
        {
            st.push({val,min(st.top().second,val)});
        }
        else st.push({val,val});
    }
    
    void pop() {

        st.pop();  
    }
    
    int top() {

        if(!st.empty()) return st.top().first;
        return -1;
        
    }
    
    int getMin() {
         if(!st.empty()) return st.top().second;
         return -1;
        
    }
};
