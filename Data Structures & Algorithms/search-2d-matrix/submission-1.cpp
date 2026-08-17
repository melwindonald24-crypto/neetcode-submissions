class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n-1;
        int mid=-1;
        bool isFound=false;

        while(low<=high)
        {
            mid=(low+high)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][m-1])
            {
                isFound=true;
                break;
            }
            else if(target<matrix[mid][0])
            {
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
        }
        if(!isFound) return false;
        low=0,high=m-1;
        while(low<=high)
        {
            int mid_j=(low+high)/2;

            if(matrix[mid][mid_j]==target)
            {
                return true;
            }
            else if(matrix[mid][mid_j]>target)
            {
                high=mid_j-1;
            }
            else{
                low=mid_j+1;
            }
        }
        return false;


        
        
    }
};
