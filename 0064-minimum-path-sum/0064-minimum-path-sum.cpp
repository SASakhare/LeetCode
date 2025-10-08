class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int>prev(n,0);
        for(int row=0;row<m;row++)
        {
            vector<int>curr(n,0);
            for(int col=0;col<n;col++)
            {

                if(row==0 && col==0) 
                    curr[col]=grid[row][col];
                else
                {
                    int up=grid[row][col]; int left=grid[row][col];
                    if(row>0)
                        up+=prev[col];
                    else 
                        up+=1e9;
                    if(col>0)
                        left+=curr[col-1];
                    else
                        left+=1e9;
                    
                    curr[col]=min(up,left);
                }

            }
            prev=curr;
        }
        
        return prev[n-1];
    }
};