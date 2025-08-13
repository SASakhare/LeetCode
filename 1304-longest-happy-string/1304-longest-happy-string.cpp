class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>>p;
        if(a>0)
            p.push(make_pair(a,'a'));
        if(b>0)
            p.push(make_pair(b,'b'));
        if(c>0)
            p.push(make_pair(c,'c'));

        string res="";

        while(!p.empty())
        {
            auto it=p.top();p.pop();

            if(it.first >= 2)
            {
                if(res.size() > 0 && res.back()==it.second)
                {
                    if(!p.empty())
                    {
                        auto next=p.top();p.pop();
                        res.push_back(next.second);
                        next.first-=1;
                        if(next.first > 0)
                        {
                            p.push(next);
                        }

                        if(it.first>0)
                        {
                            p.push(it);
                        }
                    }   
                }
                else
                {
                res.push_back(it.second);
                    res.push_back(it.second);
                    it.first-=2;
                    if(!p.empty())
                    {
                        auto next=p.top();p.pop();
                        res.push_back(next.second);
                        next.first-=1;
                        if(next.first > 0)
                        {
                            p.push(next);
                        }

                        if(it.first>0)
                        {
                            p.push(it);
                        }
                    }   
                }

            }else // only accurrence :
            {
                res.push_back(it.second);
            }
        }
    
        return res;
    }
};