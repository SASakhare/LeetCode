class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int n=str1.size();
        int m=str2.size();

        int p1=0;
        int p2=0;

        while(p1<n && p2<m)
        {
            if(str1[p1] == str2[p2])
            {
                p1++;
                p2++;
            }else 
            {
                // char ch=(str1[p1]+1)%122+'a';
                char ch = ((str1[p1]-'a') + 1)%26 +'a';
                if(ch==str2[p2])
                {
                    p2++;
                    p1++;
                }else
                {
                    p1++;
                }
            }
        }

        return p2==m ;
    }
};