class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n=position.size();
        vector<pair<int,double>>time(n);

        for(int i=0;i<n;i++)
        {
            time[i].first=position[i];
            time[i].second=(double)(target-position[i])/speed[i];
        }
        sort(time.begin(),time.end());

           int i=n-1;
           int count=0;
           double lastFleetLeader=0;
           while(i>=0)
           {
                if(time[i].second>lastFleetLeader)
                {
                    count++;
                    lastFleetLeader=time[i].second;
                }
                i--;
           }
           return count;


         
    }
};
