class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0]=-1,
        right[n-1]=-1;
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],height[i-1]);

        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i+1]);
        }
        int water=0;
        for(int i=0;i<n;i++)
        {
            int val=min(left[i],right[i])-height[i];
            if(val>0)
            {
                water+=val;
            }
        }
        return water;
        
    }
};
