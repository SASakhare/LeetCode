class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        
        
        int sum=0;
        int n=nums.size();
        int low=0;
        int high=0;
        int cnt=0;

        for(high;high<k;high++)
        {
            sum+=nums[high];
        }
        high--;

        if((sum/k)>=threshold)
        {
            cout<<"Hello"<<endl;
            cnt++;
        }
            


        while(low<=high && high<n)
        {   
            cout<<(sum/k)<<" ";
            sum-=nums[low];
            if(high+1<n)
            {
                sum+=nums[high+1];
            }
            low++;
            high++;

            if(high<n && (sum/k)>=threshold)
                cnt++;

        }

        return cnt;
    }
};