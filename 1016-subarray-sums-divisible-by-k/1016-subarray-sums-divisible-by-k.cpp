class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        int prefix=0;
        int cnt=0;

        // adding the base :

        mp[0]=1;

        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            int element=((prefix%k + k ) % k + k )%k;

            if(mp.find(element) !=mp.end())
            {
                cnt+=mp[element];
            }
            mp[element]++;
        }


        return cnt;
    }
};