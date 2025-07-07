class Solution {
    private :
    int Mod=1e9+7;
public:
    int rectangleArea(vector<vector<int>>& rect) {
        
        int n=rect.size();
        vector<tuple<int, int, int, int>>events;
        for(int i=0;i<n;i++)
        {
            // auto [x1,y1,x2,y2]=rect[i];
            int x1 = rect[i][0], y1 = rect[i][1], x2 = rect[i][2], y2 = rect[i][3];
            events.push_back({x1,y1,y2,1});
            events.push_back({x2,y1,y2,-1});
        }

        sort(events.begin(),events.end());

        // creating the sweep line:
        map<pair<int,int>,int>active;
        long long preX=0;
        long long area=0;
        int m=events.size();
        for(int i=0;i<m;i++)
        {
            auto [x,y1,y2,type]=events[i];

            // before updating the active the intervals. : we have to calculate the prev.

            if(i>0)
            {
                long long yLen=0;
                int currStart=-1,currEnd=-1;
                
                // collect all active interval :

                vector<pair<int,int>>intervals;

                for(auto &[interval,count]:active)
                {
                    if(count>0)
                    {
                        intervals.push_back(interval);
                    }
                }

                for(auto& [start,end]:intervals)
                {
                    if(start>currEnd)
                    {
                        yLen+=currEnd-currStart;
                        currStart=start;
                        currEnd=end;
                       
                    }else
                    {
                        currEnd=max(currEnd,end);
                    }
                }

                yLen+=currEnd-currStart;


                // area of vertical line :

                area = (area+(yLen *((long long)x-preX))%Mod) %Mod;

            } 

            //  Update the Active Intervals :
            active[{y1,y2}]+=type;
            preX=x;

        }

        return area;
    }
};