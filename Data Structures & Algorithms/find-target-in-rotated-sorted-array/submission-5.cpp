class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n=nums.size();
        int low=0,high=n-1;
        if(n==1 && nums[0]!=target) return -1;
        if(n==1 && nums[0]==target) return 0;
        while(low<high)
        {
            int mid=(low+high)/2;

            if(nums[mid]>nums[high])
            {
                low=mid+1;
            }else{
                high=mid;
            }
        }    
            int min_idx=low;
            if(nums[min_idx]==target) return min_idx;


            if(min_idx-1<0 || nums[min_idx-1]>=target && nums[0]<=target)
            {
                if(min_idx-1<0)
                {
                    low=0;
                    high=n-1;
                }
                else{
                    low=0;
                    high=min_idx-1;
                }
            }
            if(min_idx==n-1 || nums[min_idx+1]<=target && nums[n-1]>=target)
            {
                if(min_idx==n-1)
                {
                    high=min_idx-1;
                    low=0;
                }
                else{
                    low=min_idx+1;
                high=n-1;
                }

                
            }

            while(low<=high)
            {
                int mid=(low+high)/2;
                if(nums[mid]==target)
                {
                    return mid;
                }
                else if(nums[mid]>target)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            return -1;
            
        
    }
};
