class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        if(s.size()==0 || s[0]=='}' ||s[0]==')' || s[0]==']') return false;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='}' ||s[i]==')' || s[i]==']')
            {
                if(st.empty()) return false;

                char val=st.top();
                st.pop();
                if(s[i]=='}'&& val!='{' ||s[i]==')'&&val!='('  || s[i]==']' &&val!='[')
                {
                    return false;
                }
            }else{
                st.push(s[i]);
            }
            

        }
        return st.empty();
        
    }
};
