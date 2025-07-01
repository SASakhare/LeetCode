class Solution {
public:
    string largestMerge(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();

        int pt1=0;// word1 pointer
        int pt2=0;// word2 pointer
        string res="";

        while(pt1<n && pt2 < m)
        {
            if(word1[pt1] < word2[pt2])
            {
                res=res+word2[pt2];
                pt2++;
            }else if(word1[pt1] > word2[pt2])
            {
                res=res+word1[pt1];
                pt1++;
            }else
            {   
                if(word1.substr(pt1+1) > word2.substr(pt2+1))
                {
                    res=res+word1[pt1];
                    pt1++;
                }else
                {
                    res=res+word2[pt2];
                    pt2++;
                }

            }
              
        }

        while(pt1<n)
        {
            res=res+word1[pt1];
            pt1++;
        }

        while(pt2<m)
        {
            res=res+word2[pt2];
            pt2++;
        }
        

        return res;
    }
};