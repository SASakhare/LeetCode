class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int minRow=INT_MAX,maxRow=0;
        int minCol=INT_MAX,maxCol=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    minRow=min(minRow,i);
                    maxRow=max(maxRow,i);
                    minCol=min(minCol,j);
                    maxCol=max(maxCol,j);
                }
            }
        }

        // finding the lenght and width of rectange :

        int lenght=maxRow-minRow+1;
        int width=maxCol-minCol+1;

        return lenght*width;
    }
};