class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>res;
        
        vector<int>prev(n+1,1);
        vector<int>suff(n+1,1);
        //finding the how much long the nums[i] is smaller or equal to element before;

        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                prev[i]=prev[i-1]+1;
            }
        }

        //finding the how much long the nums[i] is smaller or equal to element after element;

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]>=nums[i])
            {
                suff[i]=suff[i+1]+1;
            }
        }

        for (int i = k; i < n - k; ++i) {
            if (prev[i-1] >= k && suff[i+1] >= k)
                res.push_back(i);
        }
        
        
        return res;

    }
};