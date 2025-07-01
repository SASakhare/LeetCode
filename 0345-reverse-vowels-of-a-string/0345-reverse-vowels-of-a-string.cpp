class Solution {
public:
    bool isVowel(char ch)
    {
        unordered_set<char> st={'a','e','i','o','u','A','E','I','O','U'};
        return st.count(ch)==1;
    }
    string reverseVowels(string s) {
        
        int n=s.size();
        int low=0;
        int high=n-1;

        while(low<high)
        {
            while(low<n && !isVowel(s[low]))
            {
                low++;
            }

            while(high>=0 && !isVowel(s[high]))
            {
                high--;
            }

            if(low<high)
            {
                swap(s[low],s[high]);
                low++;
                high--;
            }
            

        }



        return s;
    }
};