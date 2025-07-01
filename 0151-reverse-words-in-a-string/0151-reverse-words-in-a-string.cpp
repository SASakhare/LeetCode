class Solution {
public:
    string reverseWords(string s) {

        // long long ptr1 = 0;
        // long long ptr2 = 0;
        // long long n = s.size();
        // vector<string> v;
        // // string cmp=" ";
        // while (ptr1 < n && ptr2 < n) {
        //     // checking next chara will be the space.()

        //     while (ptr1 < n && s[ptr1] == ' ') {
        //         ptr1++;
        //     }
        //     // ptr2++;
        //     ptr2 = ptr1;
        //     while (ptr2 < n && s[ptr2] != ' ') {
        //         ptr2++;
        //     }

        //     int len = ptr2 - ptr1;
        //     if (ptr1 < n ) {
        //         string str = s.substr(ptr1, len);
        //         v.push_back(str);
        //     }

        //     ptr1 = ptr2;
        // }

        // string res = "";
        // n = v.size();

        // for (int i = n - 1; i >= 0; i--) {
        //     res += v[i];
        //     if (i != 0) {
        //         res += " ";
        //     }
        // }

        // return res;


        // stringstream ss(s);
        // string word;
        // vector<string>words;

        // while(ss >>word)
        // {
        //     words.push_back(word);
        // }

        // string res="";
        // int n=words.size();
        // for(int i=n-1;i>=0;i--)
        // {
        //     res+=words[i];
        //     if(i!=0)
        //     {
        //         res+=" ";
        //     }
        // }

        // return res;


        // Another Methode :

        int n=s.size();
        string res="";
        int ind=0;
        while(ind<n)
        {
            //skiping the spaces:
            while(  ind <n && s[ind]==' ')
            {
                ind++;
            }
            string word="";

            // getting complete word
            while( ind <n && s[ind]!=' ')
            {
                word=word+s[ind];
                ind++;
            }

            //adding to the result :

            if(res.empty())
            {
                 res=word;
            }else if(!word.empty())
            {
                res=word+' '+res;
            }
           

        }
        
       return  res;
    }
};