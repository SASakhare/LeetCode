class Solution {
public:
    void findLen(vector<int>&temp,int low,int high,unordered_map<int,int> &mp,long long &res)
    {
        int sum=0;
        for(int i=low;i<=high;i++)
        {
            sum+=mp[temp[i]];
        }

        if(sum>res)
        {
            res=sum;
        }
        return ;
    }
    int findLHS(vector<int>& nums) {

        int n=nums.size();
        unordered_map<int,int>mp;

        // fiding the frequency
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        //trying all possible pairs:
        vector<int>temp;
        for(auto it:mp)
        {
            temp.push_back(it.first);
        }

        sort(temp.begin(),temp.end());

        int m=temp.size();
        long long res=0;
        
        for(int i=0;i<m-1;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                if(temp[j]-temp[i] ==1)
                {
                    findLen(temp,i,j,mp,res);
                }else if(temp[j]-temp[i] >0)
                {
                    break;
                }
            }
        }

        return res;
    }
};