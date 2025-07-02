class Solution {
public:
    int compress(vector<char>& chars) {

        int n=chars.size();
        int low=0;
        int high=0;
        int ind=0;

        while(high<n)
        {
            while(high<n && chars[high]==chars[low])
            {
                high++;
            }

            if((high-low) > 1)
            {
                chars[ind]=chars[low];
                ind++;
                int num=high-low;
                string str=to_string(num);
                for(char ch:str)
                {
                    chars[ind]=ch;
                    ind++;
                }
            }else
            {
                // res++;
                chars[ind]=chars[low];
                ind++;
            }

            low=high;
        }
        return ind;
    }
};