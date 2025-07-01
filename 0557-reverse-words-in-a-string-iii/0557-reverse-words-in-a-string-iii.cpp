class Solution {
public:
    void reverseString(string & s) {
        
        int n=s.size();
        int low=0;
        int high=n-1;

        while(low<=high)
        {
            swap(s[low],s[high]);
            low++;
            high--;
        }

        return ;

    }
    string reverseWords(string s) {

        int n=s.size();
        string res="";
        int ind=0;
        while(ind<n)
        {
            //skiping the spaces:
            while(  ind <n && s[ind]==' ')
            {
                ind++;
                res=res+' ';
            }
            string word="";

            // getting complete word
            while( ind <n && s[ind]!=' ')
            {
                word=word+s[ind];
                ind++;
            }

            reverseString(word);


            //adding to the result :

            res=res+word;

        }
        
       return  res;
    }
};