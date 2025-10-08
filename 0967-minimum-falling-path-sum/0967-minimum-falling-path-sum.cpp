class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         
        int n=matrix.size();// number of row and max no of elemet in the last row.

        vector<int>prev(n,0);
        for(int i=0;i<n;i++)
        {
            prev[i]=matrix[0][i];
        }

        for(int row=1 ;row<n;row++)
        {
            vector<int>curr(n,0);
            for(int col=0;col<n;col++)
            {
                int up=matrix[row][col]+prev[col];
                int rd=matrix[row][col];
                if(col+1<n)
                    rd+=prev[col+1];
                else
                     rd+=1e9;

                int ld=matrix[row][col];
                if(col-1>=0)
                    ld+=prev[col-1];
                else
                     ld+=1e9;

                curr[col]=min(up,min(rd,ld));
            }
            prev=curr;
        }

        int minE=prev[0];
        for(int i=1;i<n;i++)
        {
            minE=min(minE,prev[i]);
        }

        return minE;
    }
};