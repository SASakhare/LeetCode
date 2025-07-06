class MyCalendarTwo {
    private :
    map<int,int>mp;
public:
    MyCalendarTwo() {
        
    }
    
    // if the time slot will be vacant then we mark it has 0,if not mark as 1.

    bool book(int startTime, int endTime) {
       
            mp[startTime]+=1;
            mp[endTime]-=1;

            int sum=0;
            for(auto &[time,mark]:mp)
            {
                    sum+=mark;
                    
                    if(sum>2)
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
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */