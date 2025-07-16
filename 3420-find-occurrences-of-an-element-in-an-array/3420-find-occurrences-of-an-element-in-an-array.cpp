class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        int m=queries.size();

        vector<int>res(m);
        unordered_map<int,int>mp;
        int occ=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==x)
            {
                mp[occ]=i;
                occ++;
            }
        }


        for(int i=0;i<m;i++)
        {
            if(mp.find(queries[i])!=mp.end())
            {
                res[i]=mp[queries[i]];
            }else
            {
                res[i]=-1;
            }
        }


        return res;
    }
};