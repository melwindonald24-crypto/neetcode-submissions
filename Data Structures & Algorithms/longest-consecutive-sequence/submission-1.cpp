class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>st;
        int n=nums.size();
        if(n==0) return 0;
        for(auto num:nums)
        {
            st.insert(num);
        }
        int max_len=1;
        for(int i=0;i<n;i++)
        {
            int start=nums[i]-1,len=1;
            while(st.find(start)!=st.end())
            {
                len++;
                start--;
                max_len=max(len,max_len);
            }
            
        }
        return max_len;
        
       
        
    }
};
