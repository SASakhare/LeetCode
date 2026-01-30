class Solution {

public:

static bool comparator(vector<int> v1,vector<int>v2)
{
    return v1[1]<v2[1];
}

// bool isRangeUsed(int l, int r,vector<pair<int,int>> &ranges)
// {
    
//     int n=ranges.size();
//     if(n==0)
//     {
//         return false;
//     }

//     for(int i=0;i<n;i++)
//     {
//         int left=ranges[i].first;
//         int right=ranges[i].second;
//         if((l >= left &&  r<=right)|| ( l >=left && left<right && r >right )||(l<left && r<=right && r>left) || (l<=left && r>=right))
//         {
//             return true;

//         }

//     }

//     return false;

// }


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
        int n=intervals.size();

        sort(intervals.begin(),intervals.end(),comparator);

        // int cnt=0;

        // vector<pair<int,int>> ranges;// ranges{left,right};

        int l=INT_MIN;
        int r=INT_MIN;
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            int left=intervals[i][0];
            int right=intervals[i][1];

            if(left>=r)
            {
                l=left;
                r=right;
                cnt++;
            }

        }

        return intervals.size()-cnt;

    }
};