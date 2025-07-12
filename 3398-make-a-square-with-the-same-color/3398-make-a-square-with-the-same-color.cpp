class Solution {
    bool fun(vector<vector<char>>&grid,int row,int col)
    {
        int cntB=0;
        int cntW=0;

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(grid[i+row][j+col]=='W')
                {
                    cntW++;
                }else
                {
                    cntB++;
                }
            }
        }

        return max(cntB,cntW)>2;
    }
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        

        return fun(grid,0,0) || fun(grid,0,1)|| fun(grid,1,0)||fun(grid,1,1);

    }
};