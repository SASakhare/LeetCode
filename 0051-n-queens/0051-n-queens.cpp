class Solution {
    private :
    bool isPlaceValid(int row,int col,vector<string>&board,int n)
    {
        // trying three direction :

        //1. left upper diagonal :  
        int nrow=row,ncol=col;
        while(nrow>=0 && ncol>=0)
        {
            if(board[nrow][ncol]=='Q')
            {
                return false;
            }
            nrow--;
            ncol--;
        }


        // 2. left directioin

        nrow=row,ncol=col;
     
        
        while(ncol>=0)
        {
            if(board[nrow][ncol]=='Q')
            {
                return false;
            }
            ncol--;
        }

        // 3. left lower diagonal direction:

        nrow=row,ncol=col;
        // int n=board.size();
        while(ncol>=0 && nrow<n)
        {
            if(board[nrow][ncol]=='Q')
            {
                return false;
            }
            ncol--;
            nrow++;
        }

        return true;
    }

    void fun(int col,vector<string>&board,vector<vector<string>>&res,int n)
    {
        // base case :
        if(col>=board.size())
        {
            res.push_back(board);
            return ;
        }

        // recursive case :

        // for perticular col trying all possible row's
        for(int i=0;i<n;i++)
        {
            if(isPlaceValid(i,col,board,n))
            {
                board[i][col]='Q';
                fun(col+1,board,res,n);
                board[i][col]='.';
            }
        }

        return ;
    }
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string>board(n);
        string temp(n,'.');

        for(int i=0;i<n;i++)
        {
            board[i]=temp;
        }

        // now 
        vector<vector<string>>res;

        fun(0,board,res,n);
        return res;
        
    }
};