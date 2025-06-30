class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //         int i,j;
        //         int l=nums.size();
        //         bool flag=false;
        //         for(i=0;i<l;i++)
        //         {
        //             for(j=i+1;j<l;j++)
        //             {
        //                 int sum=nums[i]+nums[j];
        //                 if(sum==target)
        //                 {    flag=true;
        //                     break;

        //                 }
        //             }
        //             if(flag)
        //             {
        //                 break;
        //             }
        //         }

        //    return {i,j};

        // int n = nums.size();
        // unordered_map<int, int> mymap;
        // int i;
        // for (i = 0; i < n; i++) {
        //     int x = target - nums[i];
        //     if (mymap.count(x)) {
        //         break;
        //     } else {
        //         mymap.insert({nums[i], i});
        //     }
        // }

        // return {i, mymap[target - nums[i]]};


        // Two pointer Approach:
        int n=nums.size();
        vector<pair<int,int>>temp;// vlaue , index
        for(int i=0;i<n;i++)
        {
            temp.push_back(make_pair(nums[i],i));
        }

        sort(temp.begin(),temp.end());

        int left=0;
        int right=n-1;

        while(left<=right)
        {
            int sum=temp[left].first+temp[right].first;
            if(sum==target)
            {
                break;
            }
            else if(sum<target)
            {
                left++;
            }
            else if(sum>target)
            {
                right--;
            }
        }

        return {temp[left].second,temp[right].second};
    }
};