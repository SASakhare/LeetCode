class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int res=0;
        int n=bank.size();
        int m=bank[0].size();

        int prev=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {   curr=0;
           for(int j=0;j<m;j++)
            {
                if(bank[i][j]=='1')
                {
                    curr++;
                }
            }

            res=res+(curr*prev);
            if(curr>0)
                prev=curr;
        }

        return res;
    }
};