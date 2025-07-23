class Solution {
public:

    void fun(int ind,int n,int k,vector<vector<int>>&res,vector<int>&temp)
    {
        //base case :

        if(k==0)
        {
            res.push_back(temp);
            return ;
        }
        if(ind>n)
        {
            return ;
        }

        // recursive case :

        // take the element :
        temp.push_back(ind);
        fun(ind+1,n,k-1,res,temp);

        // not take the element :
        temp.pop_back();
        fun(ind+1,n,k,res,temp);
        
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>res;
        vector<int>temp;
        fun(1,n,k,res,temp);
        return res;
    }
};