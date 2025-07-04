class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>pre(n,1);
        vector<int>suff(n,1);
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]*nums[i-1];
            suff[n-i-1]=suff[n-i]*nums[n-i];
        }

        // int totalProd=pre[n-1]*nums[n-1];

        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            // res[i]=pre[i]*(totalProd/nums[i]);
            // totalProd/=nums[i];

            res[i]=pre[i]*suff[i];
        }

        return res;
    }
};