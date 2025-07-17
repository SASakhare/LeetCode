class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        int m=s1.size();

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
            mp[s1[i]-'a']+=1;
        }

        for(int i=0;i<m;i++)
        {
            temp[s2[i]-'a']+=1;
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
                return true;
            }

            if(high+1<n)
            {
                temp[s2[low]-'a']-=1;
                temp[s2[high+1]-'a']+=1;
            }

            low++;
            high++;
        }

        return false;
    }
};