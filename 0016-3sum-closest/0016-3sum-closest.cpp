class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res[3];
        int diff=INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = (nums[i] + nums[j] + nums[k]);
                if (abs(target-sum) < diff) {
                        res[0]=nums[i];
                        res[1]=nums[j];
                        res[2]=nums[k];
                        diff=abs(target-sum);
                 }
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }

        }

        return res[0]+res[1]+res[2];
    }
};