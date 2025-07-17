class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n=s.size();
        int m=p.size();

        // if lenght of p is greather than lenght of s then it is not possible to make the p from s.
        if(m>n)
        {
            return {};
        }

        vector<int>mp(26,0);
        vector<int>temp(26,0);
        vector<int>res;

        int low=0;
        int high=m-1;


        for(int i=0;i<m;i++)
        {
            mp[p[i]-'a']+=1;
        }

        for(int i=0;i<m;i++)
        {
            temp[s[i]-'a']+=1;
        }

        while(high<n && low<=high)
        {
            // is valid one :
            bool isValid=true;

            for(int i=0;i<26;i++)
            {
                if(temp[i]!=mp[i])
                {
                    isValid=false;
                    break;
                }
            }

            if(isValid)
            {
                res.push_back(low);
            }

            if(high+1<n)
            {
                temp[s[low]-'a']-=1;
                temp[s[high+1]-'a']+=1;
            }

            low++;
            high++;
        }

        return res;
    }
};