class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1) return 0;//edge case ;
        int n=nums.size();
        long long cnt=0;
        int l=0,r=0;
        long long product=1;
        while(r<n)
        {   
            product*=nums[r];

            while(product>=k)
            {
                product/=nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }


        
        return cnt;
    }
};