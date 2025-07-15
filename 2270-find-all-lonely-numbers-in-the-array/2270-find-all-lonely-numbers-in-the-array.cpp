class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        int n=nums.size();

        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }


        for(auto it:mp)
        {
            if(it.second==1)
            {
                if(mp.find(it.first-1)==mp.end() && mp.find(it.first+1)==mp.end())
                {
                    res.push_back(it.first);
                }
            }
        }

        return res;
    }
};