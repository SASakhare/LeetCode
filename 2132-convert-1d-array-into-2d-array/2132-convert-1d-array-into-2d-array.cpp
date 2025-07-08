class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        int s=original.size();
        vector<vector<int>>res;
        if(s!=(m*n))
        {
            return res;
        }

        int ind=0;
        for(int i=0;i<m;i++)
        {   vector<int>temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(original[ind]);
                ind++;
            }
            res.push_back(temp);
        }
        
        return res;
    }
};