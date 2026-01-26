class Solution {

    int find(vector<int>&nums,int ele)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;

        while(low<=high)
        {
            int mid=low + (high-low)/2;
            if(nums[mid]>ele)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
    }
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        vector<int>res;
        sort(nums1.begin(),nums1.end());

        for(int i=0;i<n;i++)
        {
            int ele=nums2[i];

            int ind=find(nums1,ele);
            // ind point to the just biggest element :
            if(ind==nums1.size())
            {//ie. ele is greater than all element
                res.push_back(nums1[0]);
                nums1.erase(nums1.begin()+0);
            }else{
                res.push_back(nums1[ind]);
                nums1.erase(nums1.begin()+ind);
            }
        }

        return res;
    }
};