class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mpp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {

        if(mpp.find(key)!=mpp.end())
        {
            auto values=mpp[key];
            int low=0,high=values.size()-1;
            int ans=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(values[mid].first<=timestamp)
                {
                    ans=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            if(ans==-1) return "";

            return values[ans].second;
        }
        
        else{
            return "";
        }
        
    }
};
