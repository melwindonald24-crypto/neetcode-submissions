/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& inter) {

        int n=inter.size();
        sort(inter.begin(),inter.end(),[](Interval&a,Interval&b){
            return a.start<b.start;
        });
        for(int i=1;i<n;i++)
        {
            if(inter[i].start<inter[i-1].end)
            {
                return false;
            }

        }
        return true;
        
    }
};
