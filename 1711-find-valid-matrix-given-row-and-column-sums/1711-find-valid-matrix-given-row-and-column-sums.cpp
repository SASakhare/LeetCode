class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int rSum=rowSum[i];
                int cSum=colSum[j];

                int mini=min(rSum,cSum);

                ans[i][j]=mini;
                rowSum[i]-=mini;
                colSum[j]-=mini;
            }
        }  

        return ans;
    }
};