class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n=s.size();
        vector<int>changes(n+1,0);

        int m= shifts.size();

        for(int i=0;i<m;i++)
        {
            if(shifts[i][2]==0)
            {
                changes[shifts[i][0]]-=1;
                changes[shifts[i][1]+1]+=1;
            }else{
                changes[shifts[i][0]]+=1;
                changes[shifts[i][1]+1]-=1;
            }
        }
        // fiding the prefix sum:

        // for(int i=0;i<n;i++)
        int sum=0;
        for(int i=0;i<n;i++)
        {   sum+=changes[i];
            changes[i]=sum;
            if(changes[i]>0)
            {
                s[i]=(((s[i]-'a') +changes[i])%26 + 'a');

            }else if(changes[i]<0)
            {
                s[i]=(((((s[i]-'a')+changes[i]+26)%26 +26)%26 +26)%26)+'a';
            }
        }
        return s;
    }
};