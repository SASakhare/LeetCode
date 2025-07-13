class Solution {
public:

    bool fun(vector<vector<char>>& board,int rMove,int cMove,char color,bool right,bool left,bool up,bool down)
    {   
        int row=rMove;
        int col=cMove;
        char opp;
        int len=0;

        if(color=='W')
            opp='B';
        else 
            opp='W';

        while(row<8 && col<8)
        {
            if(right)
                col++;

            if(left)
                col--;

            if(up)
                row--;
            
            if(down)
                row++;

            if(col<8 and col>=0 && row<8 && row>=0 && board[row][col]==opp)
            {   len++;
                continue;
            }else
            {
                break;
            }
        }
        len+=2;
        if(col<8 && col>=0 && row<8 && row>=0 && board[row][col]==color && len>=3 )
        {
            return true;
        }

        return false;

    }
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        

        int n=8;
        int m=8;

        vector<int>r={-1,0,1};
        vector<int>c={-1,0,1};
        bool left=false,right=false;
        bool up=false,down=false;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
             {
                left=false,right=false,up=false,down=false;
                if(r[i]==-1)
                {
                    up=true;
                }
                if(r[i]==1)
                {
                    down=true;
                }

                if(c[j]==1)
                {
                    right=true;
                }
                if(c[j]==-1)
                {
                    left=true;
                }


                bool res=fun(board,rMove,cMove,color,right,left,up,down);

                if(res)
                {
                    return true;
                }

                
            }
        }

        return false;
    }
};

