class Solution {
    int fun(int ind,int n,int k,unordered_map<int,int>&mp,vector<int>&nums)
    {
        // base case :

        int cnt= (ind>0 ? 1 : 0); 
        //recursive case :

        for(int i=ind;i<n;i++)
        {
            // checking the element with perticular condition
            if(mp.find(nums[i]+k)!=mp.end() || mp.find(nums[i]-k)!=mp.end())
                continue;
            mp[nums[i]]++;
            cnt+=fun(i+1,n,k,mp,nums);
            mp[nums[i]]--;
            if(mp[nums[i]]==0)
                mp.erase(nums[i]);
        }

        return cnt;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;

        return fun( 0, n, k,mp,nums);
    }
};