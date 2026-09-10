class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count=0;
        int canidate=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                canidate=nums[i];
            }
            if(canidate==nums[i])
            {
                count++;
            }else{
                count--;
            }
        }
        return canidate;

        
    }
};