class Solution {
public:

    void findSubsets(vector<vector<int>>&res,vector<int> & nums,int index,vector<int> temp,int n)
    {
        // if(index==n+1)
        // {
        //     res.push_back(temp);
        //     return ;
        // }

        // for(int i=index;i<=n;i++)
        // {
        //     if(i>index && (i<n) && nums[i]==nums[i-1])
        //         continue;
            
        //     if(i<n)
        //     {
        //         temp.push_back(nums[i]);
        //     }
            
        //     findSubsets(res,nums,i+1,temp,n);
        //     if(i<n)
        //     {
        //         temp.pop_back();
        //     }
            

        // }

        res.push_back(temp);

        for(int i=index;i<n;i++)
        {
            if(i>index && nums[i]==nums[i-1]) 
                continue;
            temp.push_back(nums[i]);
            findSubsets(res,nums,i+1,temp,n);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>>res;

        sort(nums.begin(),nums.end());
        findSubsets(res,nums,0,{},nums.size());

        return res;
    }
};