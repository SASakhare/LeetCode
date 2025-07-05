class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        int n=logs.size();// no of queries.
        map<int,int>mp;
        // sort(logs.begin(),logs.end());

        // birth --> 1;
        // die  ---> -1;

        for(int i=0;i<n;i++)
        {
            mp[logs[i][0]]+=1;
            mp[logs[i][1]]-=1;
        }

        // int sum=0;
        // for(auto it:mp)
        // {
        //     sum=sum+it.second;
        //     mp[it.first]=sum;
        // }

        // // find the year which has max population :

        // int year=3000;
        // int pop=0;

        // for(auto it :mp)
        // {
        //     if(it.second >pop )
        //     {
        //         year=it.first;
        //         pop=it.second;
        //     }
        // }

        // return year;


        int maxPop=0;
        int currPop=0;
        int year=0;

        for(auto& [y,delta] : mp)
        {
            currPop+=delta;
            if(currPop>maxPop)
            {
                maxPop=currPop;
                year=y;
            }
        }


        return year;
    }
};