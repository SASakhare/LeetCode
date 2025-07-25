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

    int fun(int col,vector<string>&board,int n,vector<int>&leftCol,vector<int>&leftUpperDiagonal,vector<int>&leftLowerDiagonal)
    {
        // base case :
        if(col>=board.size())
        {
            // res.push_back(board);
            return 1;
        }

        // recursive case :

        // for perticular col trying all possible row's
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            // if(isPlaceValid(i,col,board,n))
            if(leftCol[i]==0 && leftUpperDiagonal[(n-1)+(col-i)]==0 && leftLowerDiagonal[i+col]==0)
            {
                board[i][col]='Q';
                leftCol[i]=1;
                leftUpperDiagonal[(n-1)+(col-i)]=1;
                leftLowerDiagonal[i+col]=1;

                cnt+=fun(col+1,board,n,leftCol,leftUpperDiagonal,leftLowerDiagonal);

                leftCol[i]=0;
                leftUpperDiagonal[(n-1)+(col-i)]=0;
                leftLowerDiagonal[i+col]=0;
                board[i][col]='.';
            }
        }

        return cnt;
    }
public:
    int totalNQueens(int n) {
        vector<string>board(n);
        string temp(n,'.');
        vector<int>leftCol(n,0);
        vector<int>leftUpperDiagonal((2*n-1),0);// formula : (n-1)+(col-row);
        vector<int>leftLowerDiagonal((2*n-1),0);// formula :  col+row :

        for(int i=0;i<n;i++)
        {
            board[i]=temp;
        }

        // now 
        // vector<vector<string>>res;

        int res=fun(0,board,n,leftCol,leftUpperDiagonal,leftLowerDiagonal);
        return res;
        
    }
};