class Solution {
    int n,m;
public:
    
    void sortDiagonal(vector<vector<int>>&mat,int row,int col)
    {
        vector<int>temp;
        int i=row;
        int j=col;
        while(i<m && j<n)
        {
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }

        sort(temp.begin(),temp.end());

        i=row;
        j=col;
        int ind=0;
        int ts=temp.size();
        while(i<m && j<n && ind<ts)
        {
            mat[i][j]=temp[ind];
            ind++;
            j++;
            i++;
        }


    }
    


    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {


        // finding dimension:

         this->m=mat.size();
         this->n=mat[0].size();

        // sort diagonal which start from the element of column 0:

        for(int row=0;row<m;row++)
        {
            sortDiagonal(mat,row,0);
        } 
        

        // sort diagonal which start from the row =0

        for(int col=0;col<n;col++)
        {
            sortDiagonal(mat,0,col);
        }

        return mat;
        
    }
};