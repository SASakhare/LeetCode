class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // int n=nums.size();
        // int occ=n/3;
        // vector<int> res;
        // unordered_map<int,int>ele;
        // for(int i=0;i<n;i++)
        // {
        //     ele[nums[i]]++;

        // }

        // for(auto itr:ele)
        // {
        //     if(itr.second > occ)
        //     {
        //         res.push_back(itr.first);
        //     }
        // }
        


        // return res;



        // Optimum :

        int n=nums.size();

        if (n<=1)
        {
            return nums;
        }


        int cnt1=0,cnt2=0;
        int el1=INT_MIN,el2=INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && el2!=nums[i])
            {
                cnt1=1;
                el1=nums[i];
            }else if(cnt2==0 && el1!=nums[i])
            {
                cnt2=1;
                el2=nums[i];
            }else if(el1==nums[i])
            {
                cnt1++;
            }else if(el2==nums[i])
            {
                cnt2++;
            }else
            {
                cnt1--;
                cnt2--;
            }
        }


        // manual checking:
         cnt1=0;
         cnt2=0;

         for(int i=0;i<n;i++)
         {
            if(el1==nums[i])
            {
                cnt1++;
            }else if(el2==nums[i])
            {
                cnt2++;
            }
         }

         vector<int>res;
         int times=n/3;
        if(cnt1>times)
        {
            res.push_back(el1);
        }

        if(cnt2>times)
        {
            res.push_back(el2);
        }

        return res;
    }
};