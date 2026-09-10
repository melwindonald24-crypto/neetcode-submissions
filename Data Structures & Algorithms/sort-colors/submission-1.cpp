class Solution {
public:
    void swap(vector<int>& nums,int i,int j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }   
    void sortColors(vector<int>& nums) {
      
        //one pass solution

        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==1)
            {
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums,mid,high);
                high--;

            }else{
                swap(nums,mid,low);
                low++;
                mid++;
            }
        }

          //two pass solution
        // int count0=0,count1=0,count2=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]==0)
        //     {
        //         count0++;
        //     }else if(nums[i]==1)
        //     {
        //         count1++;
        //     }else{
        //         count2++;
        //     }
        // }

        // for(int i=0;i<n;i++)
        // {
        //     if(count0)
        //     {
        //         nums[i]=0;
        //         count0--;
        //     }else if(count1)
        //     {
        //         nums[i]=1;
        //         count1--;
        //     }
        //     else{
        //         nums[i]=2;
        //         count2--;
        //     }
        // }


    }
};