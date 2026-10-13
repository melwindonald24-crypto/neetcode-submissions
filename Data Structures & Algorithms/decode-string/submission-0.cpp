class Solution {
public:
    string decodeString(string s) {

        stack<string>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==']')
            {
                string temp="";
                while(!st.empty() && st.top()!="[")
                {
                    temp=st.top()+temp;
                    st.pop();
                }
           
              
                    st.pop();
                    string num="";
                    while(!st.empty() && st.top().size()==1 && isdigit(st.top()[0]))
                    {
                        num=st.top()+num;
                        st.pop();
                    }
            
                    int m=stoi(num);
                    string res="";
                    for(int j=0;j<m;j++)
                    {
                        res+=temp;
                    }
                    st.push(res);
            }
            else{
                st.push(string(1,s[i]));

            }
            
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
       
        return ans;

        
        
    }
};