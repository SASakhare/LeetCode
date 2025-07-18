class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int n=s.size();
        unordered_map<char,int>charCount;
        unordered_map<string,int>strFreq;

        int low=0;
        int high=0;
        int uniqueChar=0;
        int maxFreq=0;
        while(high<n)   
        {
            charCount[s[high]]++;
            if(charCount[s[high]]==1) uniqueChar++;

            if(high-low+1 > minSize)
            {
                charCount[s[low]]--;
                if(charCount[s[low]]==0)
                {
                    uniqueChar--;
                }
                low++;
            }

            if(high-low+1==minSize && uniqueChar<=maxLetters)
            {
                string sub=s.substr(low,minSize);
                strFreq[sub]++;
                maxFreq=max(maxFreq,strFreq[sub]);
            }

            high++;
        }

        return maxFreq;
    }
};