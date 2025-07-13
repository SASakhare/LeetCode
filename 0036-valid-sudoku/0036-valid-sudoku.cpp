class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // unoredred_map<char,bool>row_map;
        // unoredred_map<char,bool>col_map;
        // unoredred_map<char,bool>sub_grid_map;

        vector<vector<int>>row_map(9,vector<int>(10,-1));
        vector<vector<int>>col_map(9,vector<int>(10,-1));
        vector<vector<int>>sub_grid_map(9,vector<int>(10,-1));
        int n=9;
        int m=9;
        // -1 is not present  and 1 is present ;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char ch=board[i][j];
                if(ch=='.')
                {
                    continue;
                }
                int num=ch-'0';

                if(row_map[i][num]!=-1)
                {
                    return false;
                }else
                {
                    row_map[i][num]=1;
                }

                if(col_map[j][num]!=-1)
                {
                    return false;
                }else
                {
                    col_map[j][num]=1;
                }

                int grid_num=3*(i/3) + (j/3);

                if(sub_grid_map[grid_num][num]!=-1)
                {
                    return false;
                }else
                {
                    sub_grid_map[grid_num][num]=1;
                }
            }
        }

        return true;
    }
};