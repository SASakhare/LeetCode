class Solution {
public:
    int fun(vector<int>&nums, int l,int r,vector<vector<int>>&dp)
    {
        if(l>r) return 0;

        if(dp[l][r]!=INT_MIN)
        {
            return dp[l][r];
        }
        int left=nums[l] - fun(nums,l+1,r,dp);
        int right=nums[r]-fun(nums,l,r-1,dp);
        return dp[l][r] = max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        return fun(nums,0,n-1,dp) >=0;
    }
};