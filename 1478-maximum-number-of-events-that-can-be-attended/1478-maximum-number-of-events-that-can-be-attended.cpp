class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
            sort(events.begin(),events.end());

            priority_queue<int, vector<int>, greater<int>> minHeap;

            int res=0;// no of event attended
            int n=events.size();
            int i=0;// index of events
            int day=1;// current Day


            while(i<n || !minHeap.empty())
            {

                // adding the events of current day in the mean heap:

                while(i<n && events[i][0]==day)
                {
                    minHeap.push(events[i][1]);
                    i++;
                }


                // removing the all events will already exprire:

                while( !minHeap.empty() && minHeap.top() < day)
                {
                    minHeap.pop();
                }


                if(!minHeap.empty())
                {
                    minHeap.pop();
                    res+=1;
                }

                day++;
            }


            return res;

    }
};