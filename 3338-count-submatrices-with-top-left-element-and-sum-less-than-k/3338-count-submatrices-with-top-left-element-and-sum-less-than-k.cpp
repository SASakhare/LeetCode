class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>AllMatrixSum(n,vector<int>(m,0));

        //finding the prefix:
        for(int i=0;i<n;i++)
        {   
           AllMatrixSum[i][0]=grid[i][0];
            int prefix=AllMatrixSum[i][0];
            for(int j=0;j<m;j++)
            {   
                if(j>0)
                {
                    AllMatrixSum[i][j]=prefix+grid[i][j];
                    prefix=AllMatrixSum[i][j];
                }
                
                if(i>0)
                {
                    AllMatrixSum[i][j]+=AllMatrixSum[i-1][j];
                }
            }
        }

        // finding the matrix sum:

        // for(int i=1;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //             AllMatrixSum[i][j]+=AllMatrixSum[i-1][j];
        //     }
        // }

        long long cnt=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(AllMatrixSum[i][j] <=k)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};