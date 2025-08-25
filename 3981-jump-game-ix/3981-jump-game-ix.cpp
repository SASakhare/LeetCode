class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n=nums.size();
        vector<int>pref_max(n,0);
        vector<int>suff_min(n,0);

        pref_max[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref_max[i]=max(pref_max[i-1],nums[i]);
        }

        suff_min[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suff_min[i]=min(suff_min[i+1],nums[i]);
        }


        vector<int>res(n,0);

        res[n-1]=pref_max[n-1];

        for(int i=n-2;i>=0;i--)
        {
            if(pref_max[i]>suff_min[i+1])
                res[i]=res[i+1];
            else 
                res[i]=pref_max[i];
        }
        
        return res;
    }
};