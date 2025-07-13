class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n=grid.size(); // no of row's
        int m=grid[0].size();// no of col's

        vector<int>res(m);
        for(int i=0;i<m;i++)
        {
            res[i]=i;
        }

        // running for each row :
        for(int i=0;i<n;i++)
        { 
            for(int j=0;j<m;j++)
            {
                int ind=res[j];
                if(ind==-1)
                    continue;
                
                int index=ind+grid[i][ind];
                if(index>=m || index<0)
                {
                    res[j]=-1;
                }
                else if( ind-1 >=0 && grid[i][ind]==-1 && grid[i][ind-1]==1)
                {
                    res[j]=-1;
                }
                else if( ind+1<m && grid[i][ind]==1 && grid[i][ind+1]==-1)
                {
                    res[j]=-1;
                }
                else{
                    res[j]=index;
                }

            }
        }



        return res;
    }
};