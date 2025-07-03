class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n=nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        for(int i=1;i<n;i++)
        {
            left[i]=nums[i-1]+left[i-1];
            right[n-1-i]=nums[n-i]+right[n-i];
        }

        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=abs(left[i]-right[i]);
        }


        return ans;
    }
};