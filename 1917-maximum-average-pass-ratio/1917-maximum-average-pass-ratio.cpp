class Solution {

    double getGain(double pass,double total)
    {
        return (pass+1)/(total+1) - (pass/total);
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>maxHeap;

        double sum=0.0;

        for(auto &cls:classes)
        {
            int pass=cls[0];
            int total=cls[1];
            sum+=(double)((double)pass/(double)total);
            maxHeap.push({getGain(pass,total),{pass,total}});
        }


        // next step:

        for(int i=0;i<extraStudents;i++)
        {
            auto [currentGain,data]=maxHeap.top();maxHeap.pop();

            int pass=data.first;
            int total=data.second;

            sum-=(double)((double)pass/(double)total);
            pass+=1;
            total+=1;

            sum+=(double)((double)pass/(double)total);
            maxHeap.push({getGain(pass,total),{pass,total}});
        }


        return sum/classes.size();
    }
};