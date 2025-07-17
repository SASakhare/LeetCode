class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int maxSum=0;
        // float maxAvg=0;
        int n=nums.size();
        int low=0;
        int high=0;

        for(high;high<k;high++)
        {
            maxSum+=nums[high];
        }
        high--;

        // let assum this is max sum :
        int sum=maxSum;
        // maxAvg=maxSum/k;

        while(low<=high && high<n)
        {   
            cout<<sum<<" ";
            sum-=nums[low];
            if(high+1<n)
            {
                sum+=nums[high+1];
            }
            low++;
            high++;

            // maxSum=max(maxSum,sum);
            if(high<n)
                maxSum=max(sum,maxSum);
                // maxAvg=max(maxAvg,sum/(k*1.0));


        }

        return (maxSum*1.0)/(k*1.0);
    }
};