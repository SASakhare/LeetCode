class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n=trips.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[trips[i][1]]+=trips[i][0];
            mp[trips[i][2]]-=trips[i][0];
        }

        // find the prefix sum :
        int sum=0;
        for(auto &[num,passanger]:mp)
        {
            sum+=passanger;
            if(sum>capacity)
            {
                return false;
            }
            mp[num]=sum;
        }
        
        return true;
    }
};