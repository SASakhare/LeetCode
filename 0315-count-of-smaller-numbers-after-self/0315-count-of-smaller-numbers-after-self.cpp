class Solution {
    void Merge(vector<pair<int,int>>&nums,vector<int>&ans,int low,int high){

        // base case 

        if(low >= high)
        {
            return ;
        }

        int mid=low + (high-low)/2;

        Merge(nums,ans,low,mid);

        Merge(nums,ans,mid+1,high);

        // 

        int left=low;
        int right=mid+1;
        vector<pair<int,int>> temp;
        int cnt=0;
        while(left<=mid && right<=high)
        {
            if(nums[left].first<=nums[right].first)
            {
                ans[nums[left].second]+=cnt;
                temp.push_back(nums[left]);
                left++;
            }else{

                // for(int i=left;i<=mid;i++)
                // {
                //     ans[nums[i].second]++;
                // }
                cnt++;
                temp.push_back(nums[right]);
                right++;
            }
        }


        while(left<=mid)
        {
            ans[nums[left].second]+=cnt;
            temp.push_back(nums[left]);
            left++;
        }

        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }

        return ;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>arr(n); // * number ,index
        int low=0;
        int high=n-1;

        for(int i=0;i<n;i++)
        {
            arr[i]=make_pair(nums[i],i);
        }


        Merge(arr,ans,low,high);

        return ans;
    }
};

/*

[ 5 , 2 , 6 , 1 ]
  0   1   2   3

[5 , 2 ]   [6 , 1]

[5]  [2]    [6]  [1]

 
*/