class Solution {
    void fun(int ind,int n,vector<int>&nums,vector<vector<int>>&res,vector<int>&temp)
    {

        // storing the ans :
        int tempSize=temp.size();
        if(tempSize>=2)
        {
            res.push_back(temp);
        }

        // recusinve case :
        unordered_set<int>used;
        for(int i=ind;i<n;i++)
        {
            if((temp.empty()|| nums[i]>=temp.back()) && used.find(nums[i])==used.end())
            {
                temp.push_back(nums[i]);
                fun(i+1,n,nums,res,temp);
                temp.pop_back();
                used.insert(nums[i]);
            }
        }
        
        return ;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        int n=nums.size();
        vector<int>temp;
        vector<vector<int>>res;
        fun(0,n,nums,res,temp);
    //    set<vector<int>>st(res.begin(),res.end());
    //     copy(st.begin(),st.end(),res.begin());
        return res;
    }
};