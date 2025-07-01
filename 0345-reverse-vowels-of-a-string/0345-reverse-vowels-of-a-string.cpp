class Solution {
public:
    bool isVowel(char &ch) {
        return ch =='a' || ch == 'e' ||
               ch =='i' || ch == 'o' ||
               ch == 'u' ||
               ch =='A' || ch == 'E' ||
               ch =='I' || ch == 'O' ||
               ch == 'U';
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