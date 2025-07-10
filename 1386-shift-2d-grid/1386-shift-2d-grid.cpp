class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {


        int m=grid.size();
        int n=grid[0].size();
        // while(k>0)
        // {

        //         int temp1=grid[m-1][n-1];
                
        //         for(int row=0;row<m;row++)
        //         {
        //             int temp2=grid[row][n-1];

        //             for(int col=n-1; col>=1 ;col--)
        //             {
        //                 grid[row][col]=grid[row][col-1];
        //             }

        //             grid[row][0]=temp1;
        //             temp1=temp2;
        //         }
        
        //     k--;
        // }

        // return grid;


        // Optimum :
        // You can flatten the grid into 1D, shift it efficiently in O(m×n), and then rebuild the grid.

        vector<int>temp;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // temp=grid[i][]
                temp.push_back(grid[i][j]);
            }
        }



        // moving circulary :

        k= k%(n*m);

        vector<int>shifted(n*m);
        for(int i=0;i<n*m;i++)
        {
            shifted[(i+k)%(n*m)]=temp[i];
        }   

        int ind=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j]=shifted[ind];
                ind++;
            }
        }


        return grid;
    }
};