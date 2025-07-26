class Solution {
public:
    bool isPowerOfTwo(int n) {
        // base condition
        //  while(true)
        //  {   int r=n%2;

        //     if(n==2 || n==1 )
        //     {
        //         return true;
        //     }
        //     else if(r==1 || n==0)
        //     {
        //         return false;
        //     }

        // n=n/2  ;
        // }

        // methode 2 :

        // long long count = 0;
        // if (n == 1) {
        //     return true;
        // }
        // while (n > 0) {
        //     n = (n) & (n - 1);
        //     count++;
        // }
        // if (count == 1) {
        //     return true;
        // } else {
        //     return false;
        // }

        // Methode 3 :

        if (n == 0 || n <= INT_MIN)
            return false;

        return (n & (n - 1)) == 0;
    }
};