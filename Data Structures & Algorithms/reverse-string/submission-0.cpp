class Solution {
public:
    void reverseString(vector<char>& s) {

        int n=s.size();
        int l=0,r=n-1;
        while(l<r)
        {
            swap(s,l,r);
            l++;
            r--;
        }
        
    }
    void swap(vector<char>&s,int i,int j)
    {
        int temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
};