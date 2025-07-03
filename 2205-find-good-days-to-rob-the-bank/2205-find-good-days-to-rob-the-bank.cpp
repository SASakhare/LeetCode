class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>pref_Cond(n,0);
        vector<int>suff_Cond(n,0);


        for(int i=1;i<n;i++)
        {
            if(security[i]<=security[i-1])
            {
                pref_Cond[i]=pref_Cond[i-1]+1;
            }
        }


        for(int i=n-2;i>=0;i--)
        {
            if(security[i]<=security[i+1])
            {
                suff_Cond[i]=suff_Cond[i+1]+1;
            }
        }

        vector<int>res;

        for(int i=0;i<n;i++)
        {
            if(i-time >=0 && i+time<n && pref_Cond[i]>=time && suff_Cond[i]>=time)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};