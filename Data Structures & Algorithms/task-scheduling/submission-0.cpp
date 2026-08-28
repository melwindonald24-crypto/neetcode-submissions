class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<int>pq;
        queue<pair<int,int>>q;
        int time=0;
        vector<int>hash(26,0);
        for(auto task:tasks)
        {
            hash[task-'A']++;
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0)
            {
                pq.push(hash[i]);
            }
        }
        while(!q.empty() || !pq.empty())
        {
            if(!q.empty() && q.front().second==time)
            {
               pq.push(q.front().first); 
                q.pop();
            }
            if(pq.empty())
            {
                time++;
                continue;
            }
            
                int maxi=pq.top();
                pq.pop();
                time++;

                if(maxi>1)
                {
                    q.push({maxi-1,time+n});
                }
            
        }

        return time;
    }
};
