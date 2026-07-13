class Solution {

    void MergeSort(vector<pair<int,int>>&arr,int low,int high){
        
        // * base case :
        
        if(low>=high)
        {
            return;
        }
        
        // * arr -> low to high (both index)
        
        int mid=low + (high-low)/2;
        
        // * low to mid 
        
        MergeSort(arr,low,mid);
        
        // * mid+1 to high
        
        MergeSort(arr,mid+1,high);
        
        
        // * when back then we have sorted half's ie. low to mid sorted and 
        // mid+1  to high sorted
        
        // * now we have to merge both hafls 
        
        vector<pair<int,int>>temp;
        
        int left=low;
        int right=mid+1;
        
        while(left<=mid && right<=high )
        {
            if(arr[left].first<=arr[right].first)
            {
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        // there should be something left in either side 
        
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        
        
        while(right<=high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        
        
        // * we have to restore the sorted ons
        
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        
        return ;
    }
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        int n=nums.size();

        vector<int>ans(n,0);

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i!=j)
        //         {
        //             if(nums[i]>nums[j])
        //             {
        //                 ans[i]++;
        //             }
        //         }
        //     }
        // }

        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i]=make_pair(nums[i],i);
        }

        MergeSort(arr,0,n-1);
        // int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i].first==arr[i-1].first)
            {
                ans[arr[i].second]=ans[arr[i-1].second];
                
            }else if(i>0 && arr[i].first>arr[i-1].first)
            {
                // cnt++;
                ans[arr[i].second]=i;
            }else if(i==0)
            {
                ans[arr[i].second]=0;
                // cnt++;
            }
        }
        return ans;
    }
};