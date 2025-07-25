class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {


        // Better :

        // int n=nums.size();
        // vector<int>pref(n,0);
        // vector<int>suff(n,0);

        // pref[0]=nums[0];
        // suff[n-1]=nums[n-1];

        // for(int i=1;i<n;i++)
        // {
        //     pref[i]=nums[i]+pref[i-1];
        //     suff[n-i-1]=nums[n-i-1]+suff[n-i];
        // }


        // vector<int>res(n,0);
        // for(int i=0;i<n;i++)
        // {
        //     int temp=suff[i]-((n-i) * nums[i]);
        //     if(i>0)
        //     {
        //         temp=temp+(nums[i]*i-pref[i-1]);
        //     }
        //     res[i]=temp;
        // }

        // return res;


        
        int n=nums.size();
        vector<int>pref(n,0);
        vector<int>suff(n,0);

        pref[0]=nums[0];
        // suff[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
        {
            pref[i]=nums[i]+pref[i-1];
            // suff[n-i-1]=nums[n-i-1]+suff[n-i];
        }


        vector<int>res(n);
        int totalSum=pref[n-1];
        for(int i=0;i<n;i++)
        {
            int left= i> 0 ? (nums[i] * i) -pref[i-1] : 0;

            int right=totalSum-pref[i]  - nums[i] * (n-i-1);

            res[i]=left+right;
        }

        return res;
    }
};