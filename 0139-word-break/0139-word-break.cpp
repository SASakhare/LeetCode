class Solution {
private :
bool fun(int ind,string s,unordered_map<string,bool>&mp,unordered_map<int,bool>&dp)
{
    // base case :
    if(ind>=s.size())
    {
        return true;
    }

    if(dp.find(ind)!=dp.end())
    { 
        return dp[ind];
    }

    // bool isValid=false;
    // Recursive case :

    for(int i=ind;i<s.size();i++)
    {
        string st=s.substr(ind,i-ind+1);
        if(mp.find(st)==mp.end()) continue;

        if(fun(i+1,s,mp,dp))
        {
            return true;
        }
        

    }

    return dp[ind]=false;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string,bool>mp;
        unordered_map<int,bool>dp;
        for(string st:wordDict)
        {
            mp[st]=true;
        }

        // int n=s.size();
        
        return fun(0,s,mp,dp);
    }   
};