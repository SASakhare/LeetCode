class Solution {
public:
    string reorganizeString(string s) {

        int n=s.size();

        // finding the freq of element :
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        // using the heap for getting max freq and next freq element :

        priority_queue<pair<int,char>>p;

        for(auto &[ch,freq] : mp)
        {
            p.push(make_pair(freq,ch));
        }

        // now  :
        string res="";
        while(!p.empty())
        {
            auto top=p.top();p.pop();
            if(res.size()>0 && res.back() == top.second)
            {
                return "";
            }
            else
            {
                res.push_back(top.second);
                top.first-=1;
                if(!p.empty())
                {
                    auto next=p.top();p.pop();
                    res.push_back(next.second);
                    next.first-=1;
                    if(next.first>0)
                    {
                        p.push(next);
                    }
                    if(top.first>0)
                    {
                        p.push(top);
                    }
                }
            }
        }

        return  n==res.size() ? res  : "";
    }
};