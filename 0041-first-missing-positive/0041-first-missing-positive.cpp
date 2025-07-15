class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // int n=nums.size();
        // unordered_map<int,int>mp;
        // int maxEl=INT_MIN;

        // for(int i=0;i<n;i++)
        // {  if(nums[i]>0)
        //     {
        //          mp[nums[i]]++;
        //          maxEl=max(maxEl,nums[i]);   
        //     }
        // }

        // if(maxEl<=0)
        //     return 1;

        // for(int i=1;i<=n;i++)
        // {
        //     if(mp.find(i)==mp.end())
        //     {
        //         return i;
        //     }
        // }

        // return -1;


        // Optimum solution :

        int n=nums.size();

        // ignoring the value >n and values<=0

        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0 || nums[i]>n)
            {
                nums[i]=n+1;
            }
        }

        // marking and element to there position :

        for(int i=0;i<n;i++)
        {
            int num=abs(nums[i]);
            if(num>n)
            {
                continue;
            }
            // checking the number is already mark :
            num--;
            if(nums[num]>0)
            {
              nums[num]=-1*nums[num]; 
            }
        }

        // finding the first index+1 which is not mark ie. index+1 is not present:

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                return i+1;
            }
        }

        return n+1;
    }
};