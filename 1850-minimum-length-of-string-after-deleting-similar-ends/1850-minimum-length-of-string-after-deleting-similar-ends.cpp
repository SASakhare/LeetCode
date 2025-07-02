class Solution {
public:
    int minimumLength(string s) {

        int n=s.size();
        int low=0;
        int high=n-1;
        // int i=0;
        // while(low<high)
        // {
        //     // char pref=s[low];
        //     int i=low;
        //     while(i+1 < n && s[i]==s[i+1])
        //         i++;
            
        //     int j=high;
        //     while( j>0 && s[j-1]==s[j])
        //         j--;
            
        //     if(s[i]==s[j])
        //     {
        //         low=i+1;
        //         high=j-1;
        //     }else
        //     {
        //         break;
        //     }
            
        // }
        // int num=(high-low+1);
        // return num < 0 ? 0 : num;
        



         // Another Solution :


        while(low<high && s[low]==s[high])
        {
            char ch=s[low];
            while(low<=high && s[low]==ch) low++;

            while(high>=low && s[high]==ch) high--;
        }

        return high-low+1;
    }
};