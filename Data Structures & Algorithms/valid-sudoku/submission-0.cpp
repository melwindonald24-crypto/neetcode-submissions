class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        //check rows
        for(int i=0;i<9;i++)
        {
            unordered_set<int> st;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(st.find(board[i][j])!=st.end())
                    {
                        return false;
                    }
                    st.insert(board[i][j]);

                }

            }
        }
        //check colums
        for(int i=0;i<9;i++)
        {
            unordered_set<int> st;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    if(st.find(board[j][i])!=st.end())
                    {
                        return false;
                    }

                }
                st.insert(board[j][i]);
            }
        }
        //check boxes
        int arr[9][2]={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        for(int k=0;k<9;k++)
        {
            unordered_set<int> st;
        for( int i=arr[k][0];i<arr[k][0]+3;i++)
        {
            for(int j=arr[k][1] ;j<arr[k][1]+3;j++)
            {
                if(board[i][j]!='.')
                {
                    if(st.find(board[i][j])!=st.end())
                    {
                        return false;
                    }

                }
                st.insert(board[i][j]);

            }
            
            }
        }
        return true;
        

        
    }
};
