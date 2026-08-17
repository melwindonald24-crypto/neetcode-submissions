class Solution {
public:
    int maxArea(vector<int>& heights) {

        int i=0,j=heights.size()-1;
        int max_area=min(heights[i],heights[j])*(j-i);

        while(i<j)
        {
            if(heights[i]<heights[j])
            {
                i++;
            }
            else{
                j--;
            }
            max_area=max(min(heights[i],heights[j])*(j-i),max_area);
        }
        return max_area;

        
    }
};
