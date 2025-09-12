class Solution {
public:

    void DFS(vector<vector<int>>&grid,int n,int m,vector<vector<int>>&vis,queue<pair<int,int>>& q,int & minutes)
    {
        int nq=q.size();

         for(int i=0;i<nq;i++)
        {
            pair<int,int>node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;

            grid[row][col]=2;
            vis[row][col]=1;

            // above :
            if(row-1>=0 && col >=0 && col<m && !vis[row-1][col] && grid[row-1][col]==1)
            {
                q.push(make_pair(row-1,col));
                vis[row-1][col]=1;
            }
            // below :
            if(row+1<n && col >=0 && col<m && !vis[row+1][col] && grid[row+1][col]==1)
            {
                q.push(make_pair(row+1,col));
                vis[row+1][col]=1;
                
            }

            // Left:
            if(row<n && row>=0 && col-1 >=0 && !vis[row][col-1] && grid[row][col-1]==1)
            {
                q.push(make_pair(row,col-1));
                vis[row][col-1]=1;
                
            }
            // Right :
            if(row<n && row >=0 && col+1 < m && !vis[row][col+1] && grid[row][col+1]==1)
            {
                q.push(make_pair(row,col+1));
                vis[row][col+1]=1;
                
            }
            
        }
        if(!q.empty()) 
        {
            minutes++;
        }

        return ;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int minutes=0;

        // 1. find all starting points:
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]==2)
                {
                    q.push(make_pair(row,col));

                }
            }
        }

        

        // apply DFS on it :

        while(!q.empty())
        {

            DFS(grid, n,m,vis,q,minutes);

        }
        //  find there any fresh orange .
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if( grid[row][col]==1)
                {
                  return -1;
                }
            }
        }


        return minutes;
    }
};

