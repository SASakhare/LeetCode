class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n=s.size();// size of s
        int m=words.size();// no of word's in the words

        if(n==0||m==0) return {};

        int wdSize=words[0].size();// size of each word
        int windownSize=wdSize*m;  // size of window :


        // taking count of each words;
        unordered_map<string,int>mp;
        for(string& st:words)
        {
            mp[st]++;
        }
        vector<int>res;

        for(int i=0;i<wdSize;i++)
        {
            unordered_map<string,int>temp;
            int r=i,l=i;

            while(r+wdSize<=n)
            {

                string sub=s.substr(r,wdSize);

                if(mp.find(sub)!=mp.end())
                {
                    temp[sub]++;

                    while(temp[sub]>mp[sub])
                    {
                        string leftWord=s.substr(l,wdSize);
                        temp[leftWord]--;
                        l+=wdSize;

                    }

                    // valid window found :

                    if(r - l +wdSize == windownSize)
                    {
                        res.push_back(l);
                    }


                }else
                {
                    temp.clear();
                    l=r + wdSize;
                }

                r += wdSize;
            }

        }

        return res;

    }
};