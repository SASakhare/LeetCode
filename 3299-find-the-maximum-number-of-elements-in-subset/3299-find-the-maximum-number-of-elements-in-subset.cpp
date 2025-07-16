class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size(); 
        unordered_map<int,int>mp;     
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }


        int maxi= mp.count(1) ? (mp[1]%2==0 ? mp[1]-1 : mp[1]) : 1;


        for(int i=0;i<n;i++)
        {
            long long val=nums[i];
            int counts=0;
            
            while(val<=1e9 && mp.count(val) && mp[val]>=2 && val!=1)
            {
                counts+=2;
                val*=val;
            }

            if(mp.count(val))
            {
                counts++;
            }else
            {
                counts--;
            }

            maxi=max(maxi,counts);

        }

        return maxi;
    }
};