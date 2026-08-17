class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n=piles.size();
        sort(piles.begin(),piles.end());
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int totalTime=0;
            for(int i=0;i<n;i++)
            {
                totalTime+=(int)ceil((double)piles[i]/piles[mid]);
            }
            if(totalTime<=h)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return piles[low];

        
    }
};
