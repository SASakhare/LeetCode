class Solution {
public:
    bool isPalindrome(string s) {
        
        string res="";
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            bool ischar=isalnum(s[i]);
            if(ischar)
            {
                res+=tolower(s[i]);
            }
        }

    int left = 0;
    int right = res.size() - 1;

    while (left < right) {
        if (res[left] != res[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;


            
    }
};