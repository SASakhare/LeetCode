class Solution {
public:
    bool check(string s,int low,int high)
    {
        while(low<high)
        {
            if(s[low]==s[high])
            {
                low++;
                high--;
            }else
            {
                return false;
            }
        }

        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int low=0;
        int high=n-1;

        int cnt=0;

        while(low<high)
        {
            if(s[low]==s[high])
            {
                low++;
                high--;
            }
            else
            {
                return check(s,low+1,high) || check(s,low,high-1);
            }
        }

        return true;
    }
};