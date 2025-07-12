class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int n=grid.size();
        // int m=grid[0].size();

        vector<int>maxRowHeight(n,0);
        vector<int>maxColHeight(n,0);

        // finding the max value from each row and column
        for(int i=0;i<n;i++)
        {   int mxRow=0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>mxRow)
                {
                    mxRow=grid[i][j];
                }

                if(grid[i][j]>maxColHeight[j])
                {
                    maxColHeight[j]=grid[i][j];
                }
            }

            maxRowHeight[i]=mxRow;
        }


        long long sum=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int height=min(maxRowHeight[i],maxColHeight[j]);

                sum+=(height-grid[i][j]);
            }
        }

            return sum;
    }
};