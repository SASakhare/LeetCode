class Solution {
public:
// possible then : true , not has then false :
        bool nextPermutation(vector<int>& permutation) {
        int index = -1;
        int n = permutation.size();

        for (int i = n - 2; i >= 0; i--) {
            if (permutation[i] < permutation[i + 1]) {
                index = i;
                break;
            }
        }

        // find the beggest smallest element.

        if (index != -1) {

            for (int i = n - 1; i >= 0; i--) {
                if (permutation[i] > permutation[index]) {
                    swap(permutation[i], permutation[index]);
                    break;
                }
            }

            reverse(permutation.begin() + index + 1, permutation.end());
        } else {

            // reverse(permutation.begin(), permutation.end());
            // return permutation;
            return false ;
        }

        // return permutation;
        return true;
    }
    int nextGreaterElement(int n) {
        
        int digits=log10(n)+1;

        vector<int>num(digits,0);
        int ind=digits-1;
        int temp=n;

        while(temp>0 && ind >=0)
        {
            int digit=temp%10;
            num[ind]=digit;
            ind--;
            temp=temp/10;
        }

        // then fiding the next permuation of the number :
        if(!nextPermutation(num))
        {
            return -1;
        }


        // making again the number back:
        long long res=0;
        for(int i=0;i<digits;i++)
        {
            if(res * 10 + (long long)num[i] > INT_MAX)
                return -1;
            res= res * 10 + num[i];
        }

        return res;

    }
};

//  2,147,483,647