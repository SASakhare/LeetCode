class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]) return -1;

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; // dist,row,col;
        // pair<int,pair<int,int>>; 
        pq.push({1,{0,0}});
        dist[0][0]=1;

        while(!pq.empty())
        {
            pair<int,pair<int,int>> node=pq.top() ;
            pq.pop();

            int d=node.first;
            int row=node.second.first;
            int col=node.second.second;

            if(row==n-1 && col==m-1) return d;
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int drow=row+i;
                    int dcol=col+j;
                    if(!(drow==row && dcol==col)  && drow>=0 && drow <n && dcol>=0 && dcol<m )
                    {
                            
                         if(!grid[drow][dcol] && d + 1 < dist[drow][dcol])
                        {
                           dist[drow][dcol]=d+1;
                            pq.push({dist[drow][dcol],{drow,dcol}});
                        }
    
                    }
                }
            
            }

        }


        if(dist[n-1][m-1]==INT_MAX) return -1;

        return dist[n-1][m-1];
    }
};