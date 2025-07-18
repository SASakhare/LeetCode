

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) { 

//---------------------------------------------------------------------------------------------------------------------------------------------
        // int n=nums.size();
        // queue<int> qu;
        // int maxLen=0;
        // int i=0;
        // while(i<n)
        // {
        //     if(nums[i]==1)
        //     {
        //         qu.push(1);
        //         i++;
        //     }
        //     else if(k>0)
        //     {
        //         qu.push(0);
        //         i++;
        //         k--;
        //     }
        //     else
        //     {
        //         // maxLen=max(maxLen,qu.size());
        //         maxLen=(maxLen > qu.size())? maxLen : qu.size();
        //         while(!qu.empty() && qu.front()==1)
        //         {
        //             qu.pop();
        //         }

        //         if(!qu.empty() && qu.front()==0)
        //         {
        //             qu.pop();
        //             // k++;
        //             qu.push(0);
        //         }
        //         i++;
        //     }

        // }
        // maxLen=(maxLen > qu.size())? maxLen : qu.size();

        // return maxLen;
        

    //----------------------------------------------------------------------------------------------------------------------------------------

        int n=nums.size();
        // int cntOne=0;
        int cntZero=0;
        int maxLen=0;

        int low=0;
        int high=0;

        while(high<n)
        {
            if(nums[high]==0)
            {
                cntZero++;
            }

            //we check is this valid windows;
            if(cntZero<=k)
            {
                maxLen=max(maxLen,high-low+1);
            }
            
            while(cntZero>k && low<high)
            {
                if(nums[low]==0)
                {
                    cntZero--;
                }
                low++;
            }
        
            high++;
        }

        return maxLen;
    }
};