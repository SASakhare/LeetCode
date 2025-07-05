class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        vector<long long>pref(n,0);
        sort(beans.begin(),beans.end());
        pref[0]=beans[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+beans[i];
        }


        long long maxSum=pref[n-1];

        long long res=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            long long left=i>0 ? pref[i-1] : 0;
            long long right=(maxSum-pref[i])-((long long)beans[i]*(long long)(n-1-i));

            if(res>left+right)
            {
                res=left+right;
            }
        }

        return res;
    }
};