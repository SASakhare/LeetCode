class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {

        int n=nums.size();
        int m=operations.size();

       unordered_map<int,int>mp;// value --> index;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }


        for(int i=0;i<m;i++)
        {
            nums[mp[operations[i][0]]]=operations[i][1];
            mp[operations[i][1]]=mp[operations[i][0]];
        }


        return nums;
        
    }
};