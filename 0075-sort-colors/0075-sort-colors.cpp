class Solution {
public:

        //** Methode 1 :
        // ￣￣￣￣￣￣￣￣￣￣
    // int partition(vector<int> & input,int left,int right)
    // {
    //     int pivot=input[left];
    //     int i=left;
    //     int j=right;

    //     while(i<=j)
    //     {
    //         while(  i<=j && input[i]<=pivot )
    //         {
    //             i++;
    //         }
    //         while( j>=i && input[j] >pivot )
    //         {
    //             j--;
    //         }
    //         if(i<j)
    //         {
    //             swap(input[i],input[j]);
    //         }
            
    //     }
    //     swap(input[left],input[j]);
    //     return j;

    // }


    // void quickSort(vector<int> & input,int left,int right)
    // {
    //     if(left>=right)
    //     {
    //         return ;
    //     }
    //     int pIndex=partition(input,left,right);
    //     quickSort(input,left,pIndex-1);
    //     quickSort(input,pIndex+1,right);

    //     return ;
    // }
    // void sortColors(vector<int>& nums) {
    
    //     quickSort(nums,0,nums.size()-1);
    //     return ;
    // }


        // Method 2 :
        // ￣￣￣￣￣￣
     void sortColors(vector<int>& nums) {
    
        int n=nums.size();
        int low=0;
        int high=nums.size()-1;
        int mid=0;

        while(mid<=high  && mid<n && low < n)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] ==1)
            {
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            

            }
        }




        return ;
    }
};