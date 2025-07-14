class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // int n=nums.size();
        // unordered_map<int,int>mp;// value and frequencey:
        // vector<int>res;

        // for(int i=0;i<n;i++)
        // {
        //     mp[nums[i]]++;
        // }

        // for(auto it:mp)
        // {
        //     if(it.second==2)
        //     {
        //         res.push_back(it.first);
        //     }
        // }

        // return res;

        int n=nums.size();
        vector<int>res;

        for(int i=0;i<n;i++)
        {
            int index=abs(nums[i]);
            index--;

            if(nums[index]<0)
            {
                res.push_back(abs(nums[i]));
            }else
            {
                nums[index]=(-nums[index]);
            }
        }


        return res;
    }
};