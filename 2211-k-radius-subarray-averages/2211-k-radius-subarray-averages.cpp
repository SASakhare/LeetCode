class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>res(n,-1);

        if(n<(2*k+1))
        {
            return res;
        }
        // vector<long long>pref(n,0);
        // pref[0]=nums[0];
        // for(int i=1;i<n;i++)
        // {
        //     pref[i]=pref[i-1]+nums[i];
        // }

        // for(int i=0;i<n;i++)
        // {
        //     int low=i-k;
        //     int high=i+k;
        //     // valid range check :
        //     if(low>=0 && high<n)
        //     {
        //         //low sum prefix[i-1] and high sum prefix[i+k]-prefix[i];
        //         long long lowSum=pref[i] - (i-k>0 ? pref[i-k-1] : 0);
        //         long long  highSum=pref[i+k]-pref[i];
        //         res[i]=(lowSum+highSum)/(2*k+1);
        //     }
        // }
        
        // return res;

        long long len=2*k+1;
        long long sum=0;

        for(int i=0;i<len;i++)
        {
            sum+=nums[i];
        }

        // checking the center k is valid or not:
        res[k]=(sum/len);

        // valid range :
        for(int i=k+1;i<=n-k-1;i++)
        {
            sum-=nums[i-k-1];
            sum+=nums[i+k];

            res[i]=(sum/len);
        }

        return res;
    }
};