class Solution {
    int findScore(int st_no,int mt_no,vector<vector<int>>&students,vector<vector<int>>&mentors)
    {
        int cnt=0;
        int n=students[0].size();
        for(int i=0;i<n;i++)
        {
            if(students[st_no][i]==mentors[mt_no][i])
            {
                cnt++;
            }
        }

        return cnt;
    }

    int fun(int len,int st_mask,int mt_mask,vector<vector<int>>&students,vector<vector<int>>&mentors,map<pair<int,int>,int>&dp)
    {
        // base case :
        if(len>=students.size())
        {
            return 0;
        }

        //recurisve case :
        if(dp.find({st_mask,mt_mask})!=dp.end())
        {
            return dp[{st_mask,mt_mask}];
        }

        int maxScore=0;
        int m =students.size();

        for(int i=0;i<m;i++)
        {
            if(st_mask & (1<<i) ) continue;
            for(int j=0;j<m;j++)
            {
                if(mt_mask & (1<<j)) continue;   
                int score=findScore(i,j,students,mentors);

                maxScore=max(maxScore,fun(len+1,(st_mask | 1<<i),(mt_mask |1<<j),students,mentors,dp) +score);

            }   
        }

        return dp[{st_mask,mt_mask}] = maxScore;
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        map<pair<int,int>,int>dp ;// it going to map pair with the integer .
        return fun(0,0,0,students,mentors,dp);
    }
};