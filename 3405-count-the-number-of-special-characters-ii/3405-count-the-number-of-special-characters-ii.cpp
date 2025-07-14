class Solution {
public:
    int numberOfSpecialChars(string word) {

        int n = word.size();

        // map<char, pair<bool, int>> mp; // isCapaticalAccured,countAfter the Capital for the
                // corresponding the charcter char:
        vector<vector<int>>mp(26,vector<int>(3,-1));// only 26 number need , -1,0,0 : isCharpresntInStr,isCapitalAccured,countAfter the Capital Accured

        for (int i = 0; i < n; i++) {
            char ch = word[i];
            // smaller letter
            if (ch >= 'a' && ch <= 'z') {
                if (mp[ch-'a'][0]!=-1 && mp[ch-'a'][1] == 1) {
                    mp[ch-'a'][2] += 1;
                } else {
                    // mp[ch] = make_pair(false, 0);
                    mp[ch-'a'][0]=1;
                    mp[ch-'a'][1]=0;
                    mp[ch-'a'][2]=0;
                }

            } else {
                // capital letter

                if(mp[ch - 'A' ][0]==1)
                    mp[ch - 'A'][1]=1;
                else
                {
                    mp[ch - 'A'][0]=1;
                    mp[ch - 'A'][1]=1;
                    mp[ch - 'A'][2]=1;
                }
            }
        }

        // iteration for finding the special char :
        int cnt = 0;    

        for(int i=0;i<26;i++)
        {
            if(mp[i][0]==1 && mp[i][1]==1 && mp[i][2]==0)
            {
                cnt++;
            }
        }

        return cnt;
    }
};