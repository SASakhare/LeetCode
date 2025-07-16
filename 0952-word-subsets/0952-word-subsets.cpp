class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        int n=words1.size();
        int m=words2.size();

        vector<int>w2(26,0);
        vector<string>res;

        // iterating to the word2 :

        for(int i=0;i<m;i++)
        {
            string word=words2[i];
            vector<int>temp(26,0);
            for(char ch:word)
            {
                int ind=ch-'a';
                temp[ind]++;
                w2[ind]=max(w2[ind],temp[ind]);
            }
        }

        // aft that :

        // iterating through the word1

        for(int i=0;i<n;i++)
        {
            string word=words1[i];
            vector<int>temp(26,0);
            for(char ch:word)
            {
                int ind=ch-'a';
                temp[ind]++;
            }

            // checking is these word is universal :
            bool isUniversal=true;
            for(int ind=0;ind<26;ind++)
            {
                if(temp[ind]<w2[ind])
                {
                    isUniversal=false;
                    break;
                }
            }

            if(isUniversal)
            {
                res.push_back(word);
            }

        }

        return res;
    }
};