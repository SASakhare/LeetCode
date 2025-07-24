class Solution {
    void fun(int num,int len,int n,int k,vector<int>&res)
    {
        // base case :
        
        if(len>=n)
        {
            res.push_back(num);
            return ;
        }


        // Recurisve Case :
        int lastDigit=num%10;
        for(int i=0;i<10;i++)
        {
                if(abs(lastDigit-i)==k)
                {   
                    fun((num*10+i),len+1,n,k,res);
                }
        }


        return ;
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
       
       vector<int>nums_mask(10,0);// we use the this vector as the masking the num index , as index values is 1 is already taken , so no need to take it again.
        vector<int>res;
        int len=1;
        // fun(0,len,n,k,nums_mask,res);

        // trying here we staring point :

        for(int i=1;i<10;i++)
        {
            fun(i,len,n,k,res);
        }
       return res;
        
    }
};