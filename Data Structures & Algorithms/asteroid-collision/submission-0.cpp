class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int>st;
        
        int n=asteroids.size();
        st.push(asteroids[0]);
        for(int i=1;i<n;i++)
        {
            if(!st.empty() && st.top()>0 && asteroids[i]<0)
            {
                while(!st.empty() && st.top()>0 && asteroids[i]<0 
                && st.top()<abs(asteroids[i]))
                {
                    st.pop();
                }
                if(!st.empty() && st.top()>0 && st.top()==abs(asteroids[i]))
                {
                    st.pop();
                }
                else if(st.empty() || st.top()<0)
                {
                    st.push(asteroids[i]);

                }

            }
            else{
                st.push(asteroids[i]);
            }
        }
        int m=st.size();
        vector<int>ans(m);
       while(m--)
       {
            ans[m]=st.top();
            st.pop();
       }
        return ans;

        
    }
};