class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();// number of row and max no of elemet in the last row.

        vector<int>prev(n,0);
        for(int i=0;i<n;i++)
        {
            prev[i]=triangle[n-1][i];
        }

        for(int row=n-2 ;row>=0;row--)
        {
            vector<int>curr(row+1,0);
            for(int col=row;col>=0;col--)
            {
                int d=triangle[row][col]+prev[col];
                int dg=triangle[row][col]+prev[col+1];
                curr[col]=min(d,dg);
            }
            prev=curr;
        }

        return prev[0];
    }
};