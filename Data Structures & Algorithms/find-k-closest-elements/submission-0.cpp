class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
        }
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        // for(int i=0,i<arr.size();i++){
        //   if(arr[s]<x){
        //   s++;}  
        //   else{
        // break;
        // }}
        // for(int i=0;i<arr.size();i++){
        //     if(arr[t]>x)
        //     t++;
        //     else{
        //     break;
        //     }}
        // for(int i=0;i<arr.size();i++){
            
        // }

    }
};