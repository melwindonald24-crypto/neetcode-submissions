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
            while(low<high)
            {
                int mid=(low+high)/2;
                if(values[mid].first<=timestamp)
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }

            return values[low].second;
        }
        else{
            return "";
        }
        
    }
};
