class Solution {
public:
    bool isVowel(char ch)
    {
        return ch=='a' || ch=='e' || ch=='i'|| ch=='o'|| ch=='u';
    }
    int maxVowels(string s, int k) {
        
            int n=s.size();
            int cnt=0;
            int low=0;
            int high=0;

            for( high;high<k;high++)
            {
                    if(isVowel(s[high]))
                    {
                        cnt++;
                    }
            }

            high--;//high=k-1

            int temp=cnt;// ASSUME CNT IS MAX :
            while(low<=high && high<n)
            {
                // shifting window's
                if(isVowel(s[low]))
                {
                    temp--;
                }

                if( high+1<n && isVowel(s[high+1]))
                {
                    temp++;
                }
                low++;
                high++;
                cnt=max(cnt,temp);
            }

        return cnt;
    }
};