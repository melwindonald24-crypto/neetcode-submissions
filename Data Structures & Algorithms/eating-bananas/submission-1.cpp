class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n=piles.size();
        int max=*max_element(piles.begin(),piles.end());
        int low=1,high=max;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int totalTime=0;
            for(int i=0;i<n;i++)
            {
                totalTime+=(int)ceil((double)piles[i]/mid);
            }
            if(totalTime<=h)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

        
    }
};
