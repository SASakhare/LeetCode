class Solution {

    bool isGaveOver(vector<string>&board ,char mark)
    {
        for(int i=0;i<3;i++)
        {
            if(board[i][0]==mark && board[i][1]==mark && board[i][2]==mark)
            {
                return true;
            }

            if(board[0][i]==mark && board[1][i]==mark && board[2][i]==mark)
            {
                return true;
            }
        }
        

        // diagonal :;

        if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
        {
            return true;
        }

        if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
        {
            return true;
        }
        return  false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        
        int n=3;
        int m=3;

        int cntX=0;
        int cntO=0;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]=='X')
                {
                    cntX++;
                }else if(board[i][j]=='O')
                {
                    cntO++;
                }
            }
        }
        bool winX=isGaveOver(board ,'X');
        bool winO=isGaveOver(board ,'O');
        
        // Rule 1: X always goes first
        if (cntO > cntX || cntX > cntO + 1) return false;

        // Rule 2: Both players cannot win at the same time
        if (winX && winO) return false;


        // Rule 3: If X wins, X must have played one more than O
        if (winX && cntX != cntO + 1) return false;

        
        // Rule 4: If O wins, countX must equal countO
        if (winO && cntX != cntO) return false;

        return true;
    }
};