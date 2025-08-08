class Solution {

    private :

    int fun(int n,vector<int>&dp)
    {
        // base case :
        if(n<=1)
        {
            return dp[n]= 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=(fun(i-1,dp) * fun(n-i,dp));
        }

        return dp[n]=ans;
    }
public:

    int numTrees(int n) {      

        vector<int>dp(n+1,-1);
        return fun(n,dp);  
    }
};