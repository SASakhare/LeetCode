class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();

        if(n<3)
            return 0;

        vector<int>mp(26,0);
        int low=0;
        int high=0;

        for(int i=0;i<3;i++)
        {
            mp[s[i]-'a']+=1;
        }

        low=0;
        high=2;
        int cnt=0;
        while(high<n && low<high)
        {
            // is valid :
            bool isValid=true;
            for(int i=0;i<26;i++)
            {
                if(mp[i]>=2)
                {
                    isValid=false;
                    break;
                }
            }
                                
            if(isValid)
            {
                cnt++;
            }

            if(high+1<n)
            {
                mp[s[low]-'a']--;
                mp[s[high+1]-'a']++;

            }

            high++;
            low++;

        }
        
        return cnt;
        
    }
};