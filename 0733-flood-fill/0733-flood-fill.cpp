class Solution {
    private :
    // dfs(image,ans,n,m,sr,sc);//

    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int n,int m,int row,int col,int inColor,int newColor,vector<int>&dRow,vector<int>&dCol)
    {
        // change the color of pixel in the image :
        ans[row][col]=newColor;

        // moving 4 direction from the point of source and check the validation pixel.
        for(int i=0;i<4;i++)
        {
            int drow=dRow[i];
            int dcol=dCol[i];

            int nRow=row+drow;
            int nCol=col+dcol;

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==inColor && ans[nRow][nCol]!=newColor)
            {
                dfs(image,ans,n,m,nRow,nCol,inColor,newColor,dRow,dCol);
            }

        }

        return ;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {


        // int n=image.size();
        // int m=image[0].size();

        // int uColor=image[sr][sc];

        // queue<pair<int,int>>q;
        // q.push(make_pair(sr,sc));
        // vector<vector<int>>vis(n,vector<int>(m,0));

        // while(!q.empty())
        // {
        //     pair<int,int>node=q.front();
        //     q.pop();
        //     int row=node.first;
        //     int col=node.second;

        //     image[row][col]=color;
        //     vis[row][col]=1;

        //     // above :
        //     if(row-1>=0 && col >=0 && col<m && !vis[row-1][col] && image[row-1][col]==uColor)
        //     {
        //         q.push(make_pair(row-1,col));
        //         vis[row-1][col]=1;
        //     }
        //     // below :
        //     if(row+1<n && col >=0 && col<m && !vis[row+1][col] && image[row+1][col]==uColor)
        //     {
        //         q.push(make_pair(row+1,col));
        //         vis[row+1][col]=1;
                
        //     }

        //     // Left:
        //     if(row<n && row>=0 && col-1 >=0 && !vis[row][col-1] && image[row][col-1]==uColor)
        //     {
        //         q.push(make_pair(row,col-1));
        //         vis[row][col-1]=1;
                
        //     }
        //     // Right :
        //     if(row<n && row >=0 && col+1 < m && !vis[row][col+1] && image[row][col+1]==uColor)
        //     {
        //         q.push(make_pair(row,col+1));
        //         vis[row][col+1]=1;
                
        //     }
            
        // }


        // return image;


        // DFS Way to solve ;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>ans=image;
        int inColor=image[sr][sc];// intial pixel color :
        vector<int>dRow={-1,0,+1,0};
        vector<int>dCol={0,+1,0,-1};

        // Checking for visited : if image[row][col]==inColor and ans[row][col]!=newColor that means that pixel not visited yet :

        dfs(image,ans,n,m,sr,sc,inColor,color,dRow,dCol);
        return ans;
    }
};