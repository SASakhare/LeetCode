class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        //* starting
        int start=abs(nums[2]-nums[n-1]);

        //* ending
        int end=abs(nums[n-3]-nums[0]);

        //* first and last :
        int first_last=abs(nums[1]-nums[n-2]);

        return min(min(start,end),first_last);
    }
};