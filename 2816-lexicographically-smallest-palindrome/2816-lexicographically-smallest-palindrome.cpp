class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        int low=0;
        int high=n-1;

        while(low<high)
        {
            if(s[low]==s[high])
            {
                low++;
                high--;
            }else if(s[low]>s[high])
            {
                s[low]=s[high];
                low++;
                high--;
            }else
            {
                s[high]=s[low];
            }
        }

        return s;
    }
};