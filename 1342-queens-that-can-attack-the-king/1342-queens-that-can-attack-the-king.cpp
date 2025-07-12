class Solution {
public:

    // void fun(vector<vector<int>>&chess,int left,int right,int up,int down,int row,int col,vector<vector<int>>&res)
    void fun(map<pair<int,int>,bool>&chess,int left,int right,int up,int down,int row,int col,vector<vector<int>>&res)
    {   
        int i=row;
        int j=col;
        while(i>=0 && i<8 && j>=0 && j<8)
        {   
            // moving i :ie.row
            if(up)
            {
                i--;
            }
            if(down)
            {
                i++;
            }
            // moing j : ie. col
            if(left)
            {
                j--;
            }

            if(right)
            {
                j++;
            }


            // if(i>=0 && i<=8 && j>=0 && j<8 && chess[i][j]==-1)
            if(i>=0 && i<=8 && j>=0 && j<8 && chess.find({i,j})!=chess.end())
            {
                res.push_back({i,j});
                return ;
            }

        }

        return ;

    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        // vector<vector<int>>chess(8,vector<int>(8,0));
            map<pair<int,int>,bool>chess;
        // marking the queen as -1 and king as 1;

        for(auto it:queens)
        {
            // chess[it[0]][it[1]]=1;
            chess[make_pair(it[0],it[1])]=true;
        }

        // chess[king[0]][king[1]]=-1;


        vector<int>r={-1,0,1};
        vector<int>c={-1,0,1};
        int row=king[0];
        int col=king[1];

        vector<vector<int>>res;
        bool left=false;
        bool right=false;
        bool up=false;
        bool down=false;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                // if r[i]==-1 --> up  and r[i]==1 ---> down

                if(r[i]==-1)
                {
                    up=true;
                }   
                if(r[i]==1)
                {
                    down=true;
                }

                // if c[j]==-1 --> left and c[j]==1 --> right
                if(c[j]==-1)
                {
                    left=true;
                }

                if(c[j]==1)
                {
                    right=true;
                }

                if(r[i]==0 && c[j]==0)
                    continue;

                fun(chess,left,right,up,down,row,col,res);

                left=false;
                right=false;
                up=false;
                down=false;
            }

        }

        return res;
    }
};