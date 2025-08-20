class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        
        priority_queue<pair<double,pair<int,int>>>maxHeap;

        int n=arr.size();

        // for(int i=0;i<n-1;i++)
        // {
        //     if(i==k) break;
        //     maxHeap.push({(double)arr[i]/(double)arr[n-1],{arr[i],arr[n-1]}});
        // }

        // we have k size of priority_queue 

        for(int i=n-1;i>0;i--)
        {
            for(int j=0;j<i;j++)
            {
                double temp=(double)arr[j]/(double)arr[i] ;
                // if(maxHeap.top().first >tem)
                // {
                //     maxHeap.pop();
                //     maxHeap.push({temp,{arr[j],arr[i]}});
                // }
                 maxHeap.push({temp,{arr[j],arr[i]}});
                if(maxHeap.size()>k)
                {
                    maxHeap.pop();
                }
            }
        }

        vector<int>res = {maxHeap.top().second.first,maxHeap.top().second.second};
        return res;
    }
};