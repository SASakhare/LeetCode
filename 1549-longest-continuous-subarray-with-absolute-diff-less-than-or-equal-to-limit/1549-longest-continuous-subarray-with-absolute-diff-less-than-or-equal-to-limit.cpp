class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int maxLen=0;

        // for(int i=0;i<n;i++)
        // {
        //     int mini=INT_MAX;
        //     int maxi=INT_MIN;
        //     for(int j=i;j<n;j++)
        //     {
        //         mini=min(mini,nums[j]);
        //         maxi=max(maxi,nums[j]);

        //         if(abs(maxi-mini)>limit)
        //         {
        //             break;
        //         }else
        //         {
        //             maxLen=max(maxLen,j-i+1);
        //         }
        //     }
        // }


        int l=0;
        // int r=0;
        deque<int> maxdq,mindq;

        for(int r=0;r<n;r++ )
        {

            while(!maxdq.empty() && nums[r]>nums[maxdq.back()])
            {
                maxdq.pop_back();
            }
            maxdq.push_back(r);


            while(!mindq.empty() && nums[r]<nums[mindq.back()])
            {
                mindq.pop_back();
            }
            mindq.push_back(r);


            while(nums[maxdq.front()]-nums[mindq.front()] >limit)
            {
                l++;
                if(maxdq.front()<l)
                {
                 maxdq.pop_front();
                }
                if(mindq.front()<l)
                {
                    mindq.pop_front();
                }
            }

            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};