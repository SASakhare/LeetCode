class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int n=boxGrid.size();// row
        int m=boxGrid[0].size();// col

        vector<vector<char>>res(m,vector<char>(n));

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                res[col][n-1-row]=boxGrid[row][col];
            }
        }


        // now  rearrangement:

        for(int col=0;col<n;col++)
        {

            int empty=m-1;

            for(int row=m-1;row>=0;row--)
            {
                if(res[row][col]=='*')
                {
                    empty=row-1;
                }else if(res[row][col]=='#')
                {
                    if(row!=empty)
                    {
                        res[empty][col]='#';
                        res[row][col]='.';

                    }
                    empty--;
                }
            }
        }

        return res;
    }
};