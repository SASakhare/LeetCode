class Solution {
public:
    int numberOfSpecialChars(string word) {

        int n = word.size();

        map<char, pair<bool, int>>
            mp; // isCapaticalAccured,countAfter the Capital for the
                // corresponding the charcter char:

        for (int i = 0; i < n; i++) {
            char ch = word[i];
            // smaller letter
            if (ch >= 'a' && ch <= 'z') {
                if (mp.find(ch) != mp.end() && mp[ch].first == true) {
                    mp[ch].second += 1;
                } else {
                    mp[ch] = make_pair(false, 0);
                }

            } else {
                // capital letter

                if(mp.find(ch+32)!=mp.end())
                    mp[ch + ('a' - 'A')].first=true;
                else
                    mp[ch + ('a' - 'A')] = make_pair(true, 1);
            }
        }

        // iteration for finding the special char :
        int cnt = 0;

        for (auto it : mp) {
            char ch = it.first;
            auto p = it.second;

            if (p.first==true && p.second == 0) {
                cout<<ch<<' ';
                cnt++;
            }
        }

        return cnt;
    }
};