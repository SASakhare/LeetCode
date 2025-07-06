class MyCalendarThree {

private :
    map<int,int>mp;

public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        
            mp[startTime]+=1;
            mp[endTime]-=1;

            int sum=0;
            int max=0;
            for(auto &[time,mark]:mp)
            {
                    sum+=mark;
                    
                    if(sum>max)
                    {
                        max=sum;
                    }
                    // temp[time]=sum;
            }

            // booking.push_back({startTime,endTime});
            // mp=temp;
            return max;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */