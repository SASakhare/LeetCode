class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>temp(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                // even row 
                if(i%2==0)
                {
                    temp[i][(((((j-k+m)%m) + m )% m)+m)%m]=mat[i][j];
                }else // odd row 
                {
                    temp[i][(j+k)%m]=mat[i][j];
                }
            }
        }
        
        // cheching the both matrix :

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(temp[i][j]!=mat[i][j])
                {
                    return false;
                }
            }
        }


        return true;
    }
};