class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        int n=nums.size();
        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i][0]]+=1;
            mp[nums[i][1]+1]-=1;
        }

        // 
        int sum=0;
        for(auto it :mp)
        {
            sum+=it.second;
            mp[it.first]=sum;
        }

        // 

        int minPoint=INT_MAX;
        int max=0;
        int res=0;
        for(auto & [point,cover]:mp)
        {
            if(cover==0)
            {
                res+=point-minPoint;
                minPoint=INT_MAX;

            }
            else{
                minPoint=min(point,minPoint);
            }
            
        }

        return res;
        
    }
};