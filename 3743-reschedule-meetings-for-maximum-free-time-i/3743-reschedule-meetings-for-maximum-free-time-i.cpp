class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        int n=startTime.size();
        vector<int>freeGap(1,startTime[0]);

        for(int i=1;i<n;i++)
        {
            freeGap.push_back(startTime[i]-endTime[i-1]);
        }
        freeGap.push_back(eventTime-endTime.back());

        int maxFreeDuration =0 , currentSum=0;
        int m=freeGap.size();
        for(int i=0;i<m;i++)
        {
            currentSum+=freeGap[i] - ((i>=(k+1)) ? freeGap[i-(k+1)] : 0);
            maxFreeDuration=max(maxFreeDuration,currentSum);
        }


        return maxFreeDuration;
    }
};