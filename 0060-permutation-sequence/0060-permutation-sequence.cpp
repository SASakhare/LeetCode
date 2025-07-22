class Solution {
    private :
    string helper(vector<int>&nums,int k,int fact)
    {    if(nums.size()==0)
        {
            return "";
        }
        string res=to_string(nums[k/fact]);
        nums.erase(nums.begin()+k/fact);
        k=k%fact;
        if(nums.size()==0)
        {
            return res;
        }
        fact=fact/nums.size();
        res+=helper(nums,k,fact);
        return res;

    }
public:
    string getPermutation(int n, int k) {
        
        int fact=1;
        vector<int>nums;
        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string res="";
        k=k-1;
    //     while(true)
    //     {
    //         res+=to_string(nums[k/fact]);
    //         nums.erase(nums.begin()+k/fact);
    //         if(nums.size()==0)
    //         {
    //             break;
    //         }
    //         k=k%fact;
    //         fact=fact/nums.size();
    //     }
    // return res;
        return helper(nums,k,fact);
    }
};