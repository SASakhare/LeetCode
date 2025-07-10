class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {

        int n=grid.size();
        vector<int>y_mp(3,0);
        vector<int>nt_y_mp(3,0);


        int mid_row=n/2;
        int mid_col=n/2;

        int total_nt_y=0;

        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<n;j++)
            {
                if(i==j && i<=mid_row && j<=mid_col )
                {
                    y_mp[grid[i][j]]++;
                }else if(j==n-1-i && i<mid_row && j>mid_col)
                {
                    y_mp[grid[i][j]]++;
                }else if(i>mid_row && j==mid_col)
                {
                    y_mp[grid[i][j]]++;
                }else
                {
                    nt_y_mp[grid[i][j]]++;
                    total_nt_y++;
                }
            }
        }
        
            int res=INT_MAX;
           int total_y=(n*n)-total_nt_y;

            for(int y=0;y<3;y++)
            {
                int take=y_mp[y];

                int cnt=0;
                for(int nt_y=0;nt_y<3;nt_y++ )
                {
                    if(y!=nt_y)
                    {
                        cnt=max(cnt,nt_y_mp[nt_y]);
                    }
                }

                int temp=(total_y-take) + (total_nt_y-cnt);

                res=min(res,temp);
            }

            return res;
    }
};