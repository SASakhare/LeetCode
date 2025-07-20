class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n=fruits.size();
        unordered_map<int,int>freq;
        int r=0;
        int l=0;
        int maxLen=0;

        while(r<n)
        {   
            if(freq.size()<=1)
            {
                freq[fruits[r]]++;
            }else if(freq.size()==2 && freq.find(fruits[r])!=freq.end())
            {
                freq[fruits[r]]++;
            }else
            {
                // shrinking the window :
                maxLen=max(maxLen,r-l);
                while(l<=r)
                {
                    freq[fruits[l]]--;
                    if(freq[fruits[l]]==0)
                    {
                        freq.erase(fruits[l]);
                        l++;
                        break;
                    }
                    l++;
                }
                freq[fruits[r]]++;
            }


            r++;
        }

        maxLen=max(maxLen,r-l);

        return maxLen;
        
    }
};