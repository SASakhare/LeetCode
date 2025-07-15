class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxEl=INT_MIN;

        for(int i=0;i<n;i++)
        {  if(nums[i]>0)
            {
                 mp[nums[i]]++;
                 maxEl=max(maxEl,nums[i]);   
            }
        }

        if(maxEl<=0)
            return 1;

        for(int i=1;i<=maxEl;i++)
        {
            if(mp.find(i)==mp.end())
            {
                return i;
            }
        }

        return maxEl+1;
    }
};