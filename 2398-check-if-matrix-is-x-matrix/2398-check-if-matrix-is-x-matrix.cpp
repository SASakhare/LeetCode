class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if((row==col || col==m-1-row ) && grid[row][col]==0)
                {
                    return false;
                }else if(!(row==col || col==m-1-row ) && grid[row][col]!=0)
                {
                    return false;
                }
            }
        }


        return true;

    }
};