class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {


        int m=grid.size();
        int n=grid[0].size();
        while(k>0)
        {

                int temp1=grid[m-1][n-1];
                
                for(int row=0;row<m;row++)
                {
                    int temp2=grid[row][n-1];

                    for(int col=n-1; col>=1 ;col--)
                    {
                        grid[row][col]=grid[row][col-1];
                    }

                    grid[row][0]=temp1;
                    temp1=temp2;
                }
        
            k--;
        }

        return grid;
    }
};