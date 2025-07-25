class Solution {

private :
    bool fun(int n,vector<vector<int>>&grid,int row,int col,int i,int j)
    {
        int nrow=row;
        int ncol=col;

        if(i==0 && j==0)
        {
            return grid[row][col]==1;
        }

        while(nrow>=0 && ncol>=0 && nrow<n && ncol<n)
        {
            if(grid[nrow][ncol]==1)
            {
                return true;
            }
            nrow+=i;
            ncol+=j;
            // cout<<"row "<<nrow<<" "<<"col "<<ncol<<endl;
        }

        return false;
    }
    bool isPlaceIlluminated(int n,vector<vector<int>>&grid,int row,int col )
    {
        // checking the place row and col is Illuminated

        bool isIlluminated=false;
        // we have 8 directions to check :
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                // making 8 directinal by adding i and j:
                // if(i==0 && j==0)continue;
                isIlluminated=fun(n,grid,row,col,i,j);
                if(isIlluminated)
                {
                    break;
                }
            }

            if(isIlluminated)
            {
                break;
            }
        }

        // if(isIlluminated==false)
        // {
        //     return false;
        // }

        // is true: turned off the light of adjacnet :

        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(row+i>=0 && row+i<n && col+j>=0 && col+j<n)
                {
                    grid[row+i][col+j]=0;
                }
            }
        }
        grid[row][col]=0;

        return isIlluminated;
    }
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        // int m=queries.size();// no of queries : 
        // vector<int>res(m,0);// assume all not illuminated

        // vector<vector<int>>grid(n,vector<int>(n,0));// grid of lights : 1 -- on , 0 -- off
        

        // // marking which lamps are on :
        // for(auto it:lamps)
        // {
        //     grid[it[0]][it[1]]=1;
        // }

        // // checking for each query is to be the illuminatedL

        // for(int i=0;i<m;i++)
        // {
        //     int row=queries[i][0];
        //     int col=queries[i][1];
        //     if(isPlaceIlluminated(n,grid,row,col))
        //     {
        //         res[i]=1;
        //     }
        // }

        // return res;



        // Optimum :

        // we track that for perticular row,col,diag ,anti-dia how may lamps are there:

        unordered_map<int,int>row,col,dig,ant_dig;
        unordered_map<long long ,bool>grid;
        // initialze the lamps:
        for(auto lamp:lamps)
        {
            int r=lamp[0];
            int c=lamp[1];

            long long key=((long long )r<<32|c);

            if(grid.find(key)==grid.end())
            {
                grid[key]=true;

                row[r]++;
                col[c]++;
                dig[r+c]++;
                ant_dig[r-c]++;
            }
        }


        // iterating to the quereies :

        vector<int>res;

        for(auto q:queries)
        {
            int r=q[0];
            int c=q[1];

            if(row[r]>0 || col[c]>0 || dig[r+c]>0 || ant_dig[r-c]>0)
            {
                res.push_back(1);
            }else
            {
                res.push_back(0);
            }


            // turning off the adjacent light's
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(r+i>=0 && r+i<n && c+j>=0 && c+j<n)
                    {
                        long long key=((long long)(r+i)<<32|(c+j));

                        if(grid.find(key)!=grid.end())
                        {
                            grid.erase(key);
                            row[r+i]--;
                            col[c+j]--;
                            dig[(r+i)+ (c+j)]--;
                            ant_dig[(r+i)-(c+j)]--;
                        }
                    }
 
                }
            }

        }

        return res;
    }
};