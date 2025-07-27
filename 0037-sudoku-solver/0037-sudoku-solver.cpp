class Solution {
    bool isValid(char ch,vector<vector<char>>& board,int row,int col)
    {
        int n=9;
        for(int i=0;i<n;i++)
        {
            // checking in the row 
            if(board[row][i]==ch)
            {
                return false;
            }
            
            //checking in the col
            if(board[i][col]==ch)
            {
                return false;
            }

            //  checking in the grid :
            int r=3*(row/3) + i%3;
            int c=3*(col/3) + i/3;
            if(board[r][c]==ch)
            {
                return false;
            }
            
        }

        return true;
    }
    bool solve (vector<vector<char>>& board)
    {
        int n=9;
        int m=9;
         
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // checking the i,j place is vacant,ie.'.'
                if(board[i][j]!='.') continue;

                // if there is has vacant' try every possible one number :
                for(char ch='1';ch<='9';ch++)
                {
                    if(!isValid(ch,board,i,j)) continue;
                    board[i][j]=ch;
                    if(solve(board))
                    {
                        return true;
                    }   
                    board[i][j]='.';
                }
                return false;
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
        return ;
    }
};