class Solution {
public:
    int bestClosingTime(string customers) {

        int n=customers.size();
        vector<int>Y(n+1,0),N(n+1,0);

        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y')
            {
                Y[i]=1;
            }else
            {
                N[i]=1;
            }
        }

        
        // shifted one postion forward :
        for(int i=n;i>0;i--)
        {
            N[i]=N[i-1];
        }

        // finding the prefix for N with (0 as first) and suffix for Y sum :
        for(int i=n-1;i>=0;i--)
        {
            //suffix:
            // Y[n-i]=Y[n-i]+Y[n-i+1];
            Y[i]=Y[i]+Y[i+1];

        }

        for(int i=1;i<=n;i++)
        {
            N[i]=N[i]+N[i-1];
        }


        int ind=-1;
        int sum=INT_MAX;

        for(int i=0;i<=n;i++)
        {
            int penalty=Y[i]+N[i];

            if(penalty<sum)
            {
                ind=i;
                sum=penalty;
            }
        }


        return ind;
    }
};