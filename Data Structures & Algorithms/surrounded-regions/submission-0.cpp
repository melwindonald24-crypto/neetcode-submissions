class Solution {
public:
    void solve(vector<vector<char>>& board) {

        queue<pair<int,int>>q;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                board[i][0]='S';
            }
            if(board[i][m-1]=='O')
            {
                q.push({i,m-1});
                board[i][m-1]='S';
            }
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                q.push({0,j});
                board[0][j]='S';
            }
            if(board[n-1][j]=='O')
            {
                q.push({n-1,j});
                board[n-1][j]='S';
            }
        }
        while(!q.empty())
        {
            int size=q.size();

            for(int k=0;k<size;k++)
            {
                auto top=q.front();
                q.pop();
                int i=top.first,j=top.second;
                BFS(board,q,i+1,j);
                BFS(board,q,i-1,j);
                BFS(board,q,i,j+1);
                BFS(board,q,i,j-1);
            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='S')
                {
                    board[i][j]='O';
                }
                
            }
        }
        
    }
    void BFS(vector<vector<char>>& board,queue<pair<int,int>>&q,int i,int j)
    {
        if(i>=board.size() || i<0 ||j>=board[0].size() || j<0 || 
        board[i][j]=='X' || board[i][j]=='S')
        {
            return;
        }
        board[i][j]='S';
        q.push({i,j});

    }
};
