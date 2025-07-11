class Solution {
public:

    int findNeighbour(vector<vector<int>>&board ,int n,int m,int row,int col)
    {
        int cnt=0;
        vector<int> rw={-1,0,1};
        vector<int>cl={-1,0,1};

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {

                    int nRow=row+rw[i];
                    int nCol=col+cl[j];
                    if(!(nRow==row && nCol==col) && nRow>=0 && nCol>=0 && nRow<n && nCol<m)
                        cnt+=board[nRow][nCol];
            }
        }

        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {

        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>index;//{row,col,value}  : value -- 1, 0

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                int cnt=findNeighbour(board,n,m,row,col);

                if(board[row][col]==0 && cnt==3)
                {
                    index.push_back({row,col,1});
                }else
                {   // <2 dead :
                    if(cnt<2)
                    {
                        index.push_back({row,col,0});
                    }else if( cnt>3)
                    { // dead due to over Popluation :
                        index.push_back({row,col,0});
                    }
                }
                
            }
        }


        // for(auto it:index)
        // {
        //     board[it[0]][it[1]]=it[2];
        // }

        int len=index.size();

        for(int i=0;i<len;i++)
        {
            board[index[i][0]][index[i][1]]=index[i][2];
        }

        
        return ;
        // return board;
    }
};