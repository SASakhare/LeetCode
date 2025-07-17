class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int n=s.size();
        vector<int>mp(pow(2,k),0);

        int low=0;
        int high=k-1;


        while(low<=high && high<n)
        {

            long long value=0; // max value of k is 20 (given)
            int pw=0;
            for(int i = high ;i >= low ; i--)
            {
                value+=(s[i]=='1' ? pow(2,pw):0);
                pw++;
            }

            mp[value]=1;// mark this no is present 

            low++;
            high++;

        }

    // iterating to mp  checking for is all code's present;

        int len=pow(2,k);
        for(int i=0;i<len;i++)
        {
            if(mp[i]==0)
            {
                return false;
            }
        }

        return true;
        
    }
};