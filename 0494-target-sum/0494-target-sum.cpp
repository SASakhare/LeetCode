// class Solution {
// public:
//         struct pair_hash {
//         size_t operator()(const pair<int, int>& p) const {
//             return hash<int>()(p.first) ^ hash<int>()(p.second << 1);
//         }
//     };

//     // the fun(n-1,target) return the number of expression by using -,+, from 0 to n-1 elements in the array :
//     int fun(int ind,int target,vector<int>& nums,unordered_map<pair<int,int>,int,pair_hash>&dp)
//     {

//         //base case :
//         if(ind==0)
//         {
//             // in case of zeros : +,-
//             int count=0;
//             if(target==nums[0]) count+= 1;
//             if(target==-nums[0]) count+= 1;

//             return count;
//         }


//         // recursive case :
//         // + , - 

//         if( dp.find(make_pair(ind,target))!=dp.end()) return dp[make_pair(ind,target)];

//         int minus=fun(ind-1,target-nums[ind],nums,dp);

//         int plus= fun(ind-1,target+nums[ind],nums,dp);

//         return dp[make_pair(ind,target)] = minus+plus;

//     }
//     // int findTargetSumWays(vector<int>& nums, int target) {
//     //     int n=nums.size();
//     //     return fun(n-1,target,nums);
//     // }

//     // memoization :
    
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();
//         unordered_map<pair<int,int>,int,pair_hash>dp;// pair(n,target) --> value :

//         return fun(n-1,target,nums,dp);
//     }
// };


class Solution {

private :

        int fun(vector<int>&nums,int ind,int sum,int  target)
        {
            //base case :

            if(ind>=nums.size())
            {
                if(sum==target)
                {
                    return 1;
                }
                return 0;
            }

            // Recursive case :

            //take with + 

            int plus=fun(nums,ind+1,sum+nums[ind],target);

            // take with -

            int minus=fun(nums,ind+1,sum-nums[ind],target);

            return plus+minus;
        }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return fun(nums,0,0,target);
    }
};






















