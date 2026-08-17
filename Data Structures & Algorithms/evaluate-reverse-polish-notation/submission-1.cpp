class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(isdigit(tokens[i][0]) ||
            (tokens[i].size() > 1 && tokens[i][0] == '-'))
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                calculate(tokens[i][0],st);
            }

        }
        return st.top();
        
    }
    void calculate(char op,stack<int>&st)
    {
        int op2=st.top();
        st.pop();
        int op1=st.top();
        st.pop();
        int res;
        switch(op)
        {
            case '*':
            res=op1*op2;
            break;
            case '+':
            res=op1+op2;
            break;
            case '-':
            res=op1-op2;
            break;
            case '/':
            res=op1/op2;
            break;
        }
        st.push(res);
    }
};
