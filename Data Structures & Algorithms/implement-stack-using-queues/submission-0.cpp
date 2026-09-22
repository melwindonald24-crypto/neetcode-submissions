class MyStack {
public:

    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        
        if(q1.empty() && q2.empty())
        {
            q1.push(x);
            return;
        }
        if(!q1.empty())
        {
            q1.push(x);
            return;
        }
        q2.push(x);
        
    }
    
    int pop() {

        if(q1.empty() && q2.empty())
        {
            return -1;
        }
        int top;
        
            while(!q1.empty())
           {
                 top=q1.front();
                q1.pop();
                if(q1.empty()) return top;
                q2.push(top);
            
            }
        
        
             while(!q2.empty())
            {
                 top=q2.front();
                q2.pop();
                if(q2.empty()) return top;
                q1.push(top);
            
            }
        
       
        
    }
    
    int top() {
        
        if(q1.empty() && q2.empty())
        {
            return -1;
        }
        int top;
        
            while(!q1.empty())
           {
                top=q1.front();
                q1.pop();
                q2.push(top);
                if(q1.empty()) return top;
                
            
            }
        
        
             while(!q2.empty())
            {
                top=q2.front();
                q2.pop();
                q1.push(top);
                if(q2.empty()) return top;
                
            
            }
        
    }
    
    bool empty() {

        return q1.empty()&&q2.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */