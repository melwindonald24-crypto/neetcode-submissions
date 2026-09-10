class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int n=nums.size();
        int i=0,j=0;
        int count=0;
        while(i<n && j<n)
        {
            if(nums[i]!=val)
            {
                i++;
                j=i;
            }
            else{
                j=i+1;
                while(j<n && nums[j]==val)
                {
                    j++;
                }
                 if(j>=n) break;

                    int temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                
                i++;
            }
        }
        return i;
   
    }
};