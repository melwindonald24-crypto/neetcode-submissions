class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums,0,nums.size()-1);
        return nums;

    }
    void mergeSort(vector<int>&nums,int low,int high)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    void merge(vector<int>&nums,int low,int mid,int high)
    {
        int i=low,j=mid+1;
        vector<int>ans(high+1);
        int k=0;
        while(i<=mid && j<=high)
        {
            if(nums[i]<nums[j])
            {
                ans[k++]=nums[i++];
            }
            else
            {
                ans[k++]=nums[j++];
            }
        }
        while(i<=mid) ans[k++]=nums[i++];
        while(j<=high) ans[k++]=nums[j++];

        for(i=low;i<=high;i++)
        {
            nums[i]=ans[i-low];
        }
    }
};