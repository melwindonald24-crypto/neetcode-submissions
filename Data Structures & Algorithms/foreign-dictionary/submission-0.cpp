class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        if(words.size()==1) return words[0];

        vector<vector<int>>adj(26,vector<int>(26,0));
        vector<int>indegree(26);
        vector<bool>present(26);
        // for(auto word:words)
        // {
        //     for(auto ch:word)
        //     {
        //         present[ch-'a']=true;
        //     }
        // }

        for(int i=1;i<words.size();i++)
        {
            vector<char>edge=getDependency(words[i-1],words[i]);
            if(!edge.empty()){

                char u=edge[0]-'a';
                char v=edge[1]-'a';
                if(adj[u][v]!=1)
                {
                    adj[u][v]=1;
                    indegree[v]++;
                    present[u]=true;
                    present[v]=true;
                }
                
            }
        }
    
        bool isProcessing=false;
        
        string ans="";
        while(true)
        {
            int i;
            for( i=0;i<indegree.size();i++)
            {
                if(present[i] && indegree[i]==0)
                {
                    ans+=(char)(i+(int)'a');
                    indegree[i]=-1;
                    isProcessing=true;
                    break;

                }
            }
            if(!isProcessing) break;

            for(int j=0;j<26;j++)
            {
                if(adj[i][j]==1)
                {
                    indegree[j]--;
                }
            }
            isProcessing=false;

        }
        return ans;
        
        
    }
    vector<char> getDependency(string word1,string word2)
    {
        int n1=word1.size();
        int n2=word2.size();
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(word1[i]!=word2[j])
            {
                return {word1[i],word2[i]};
            }
            i++;
            j++;
        }    
        
        return {};
    }

};
