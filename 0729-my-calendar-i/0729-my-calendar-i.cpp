class MyCalendar {
    private :
    // vector<vector<int>>booking;
    map<int,int>mp;

public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        
            // if(booking.empty())
            // {
            //     booking.push_back({startTime,endTime});
            //     return true;
            // }

            // using sweep line alog , it anyone has greater than 1 mark then false;

           
            // int n=booking.size();
            // map<int,int>temp=mp;
            // for(int i=0;i<n;i++)
            // {
            //     mp[booking[i][0]]+=1;
            //     mp[booking[i][1]]-=1;
            // }

            mp[startTime]+=1;
            mp[endTime]-=1;

            int sum=0;
            for(auto &[time,mark]:mp)
            {
                    sum+=mark;
                    
                    if(sum>1)
                    {
                        mp[startTime]-=1;
                        mp[endTime]+=1;

                        if (mp[startTime] == 0) mp.erase(startTime);
                        if (mp[endTime] == 0) mp.erase(endTime);                        
                        return false;
                    }
                    // temp[time]=sum;
            }

            // booking.push_back({startTime,endTime});
            // mp=temp;
            return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */