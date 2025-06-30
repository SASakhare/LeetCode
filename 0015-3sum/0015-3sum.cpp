#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

        //     int n=nums.size();
        //     set<vector<int>>st;

        //     for(int i=0;i<n;i++)
        //     {
        //         set<int>mp;
        //         for(int j=i+1;j<n;j++)
        //         {
        //             int num=-(nums[i]+nums[j]);
        //             if(mp.find(num)!=mp.end())
        //             {
        //                 vector<int>r={nums[i],nums[j],num};
        //                 sort(r.begin(),r.end());
        //                 st.insert(r);
        //             }
        //             mp.insert(nums[j]);
        //         }
        //     }

        //   vector<vector<int>>res(st.begin(),st.end());

        //   return res;

        // 2nd Method :

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = (nums[i] + nums[j] + nums[k]);
                if (sum == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    // j++;
                    while (j < (n - 1) && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;

                    while (k > 0 && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    k--;
                    // continue;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
                // j++;
            }

            // while(i<n && (nums[i]==nums[i+1]) )
            // {
            //     i++;
            // }

            // i++;
        }

        return res;
    }
};
