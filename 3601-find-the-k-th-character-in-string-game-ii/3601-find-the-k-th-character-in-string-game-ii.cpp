class Solution {
public:
    string fun(string &word)
    {
            string temp=word;
            int n=word.size();
            for(int i=0;i<n;i++)
            {
                char ch= (temp[i]-'a' + 1 ) % 26 + 'a';
                temp[i]=ch;
            }
            // temp;

            return temp;
    }
    char kthCharacter(long long k, vector<int>& operations) {


        // Brute Force and better one :

        // int n=operations.size();
        // string word="a";

        // for(int i=0;i<n;i++)
        // {  
        //     if(word.size()>=k)
        //     {
        //         break;
        //     }
        //     if(operations[i]==0)
        //     {
        //         // string temp=word;
        //         word=word+word;

        //     }else
        //     {
        //         string temp=fun(word);
        //         word=word+temp;
        //     }
        // }
        
        // // cout<<word<<endl;
        // return word[k-1];



        // Optimum :

        int n=operations.size();
        long long lastIndex=0;
        long long len=1;

        for(int i=0;i<n;i++)
        {
            len=len<<1;
            if(len>=k)
            {
                lastIndex=i;
                break;
            }
            
        }


        // 

        int shiftCount=0;

        for(int i=lastIndex;i>=0;i--)
        {
            len/=2;

            if(len<k)
            {
                k=k-len;
                if(operations[i]==1)
                {
                    shiftCount++;
                }

            }
        }

        shiftCount%=26;

        return 'a'+shiftCount;
    }
};