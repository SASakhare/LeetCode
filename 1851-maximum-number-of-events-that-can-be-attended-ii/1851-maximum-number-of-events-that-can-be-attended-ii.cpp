class Solution {

    private :
    // map<pair<pair<int,int>,int>,int>dp;

    vector<vector<int>>dp;
    vector<int>next;

public:

    // Memoization solution  Method 1 :

    // int fun(int ind,int lastDay,int k,int n,vector<vector<int>>&events)
    // {

    //     //base case :

    //     if(ind>=n)
    //     {

    //         return dp[{{ind,lastDay},k}]=0;

    //     }

    //     if(k<=0)
    //     {
    //         return dp[{{ind,lastDay},k}]=0;
    //     }


    //     if(dp.find({{ind,lastDay},k})!=dp.end())
    //     {
    //         return dp[{{ind,lastDay},k}];
    //     }

    //     // Recursive Case :

    //     int notAttend=fun(ind+1,lastDay,k,n,events);

    //     int attend=0;
    //     if(events[ind][0]>lastDay)
    //     {
    //         k--;
    //         attend=fun(ind+1,events[ind][1],k,n,events)+events[ind][2];
    //         k++;
    //     }


    //     return dp[{{ind,lastDay},k}]=max(attend,notAttend);
    // }


    // Memoization method 2 : of lastDay is not state variable :

        int fun(int ind,int k,int n,vector<vector<int>>&events)
    {
        //base case :
        if(ind>=n || k<=0)
        {

            return dp[ind][k]=0;

        }

        if(dp[ind][k]!=-1)
        {
            return dp[ind][k];
        }

        // Recursive Case :

        int notAttend=fun(ind+1,k,n,events);

        int attend=events[ind][2] + fun(next[ind],k-1,n,events);


        return dp[ind][k]=max(attend,notAttend);

    }



    int maxValue(vector<vector<int>>& events, int k) {
        
        int n=events.size();
        sort(events.begin(),events.end());
        next.resize(n,n);

        for(int i=0;i<n;i++)
        {
            int lo=i+1,hi=n;

            while(lo<hi)
            {
                int mid=(lo+hi)/2;

                if(events[mid][0]>events[i][1])
                {
                    hi=mid;
                }else
                {
                    lo=mid+1;
                }
            }
            next[i]=lo;
        }
        
        // dp.assign(n+1, vector<int>(k + 1, -1));
        // return fun(0,k,n,events);

            // Tabulation Solution :

            dp.assign(n+1,vector<int>(k+1,0));

            // ind=n then k=0 --- k
            // for(int i=0;i<=k;i++)
            // {
            //     dp[n][i]=0;
            // }

            // //k=0 then ind :[ 0 n]

            // for(int i=0;i<=n;i++)
            // {
            //     dp[i][k]=0;
            // }

          //  recursive case : ind : 0 --> n in Bottom Up : n-1 to 0; and k : k -->1 so k=1 to k

          for(int ind=n-1;ind>=0;ind--)
          {
            for(int K=1;K<=k;K++)
            {
                int notAttend=dp[ind+1][K];

                int attend=events[ind][2] + dp[next[ind]][K-1];


                dp[ind][K]=max(attend,notAttend);

            }

          }


        return dp[0][k];

    }
};