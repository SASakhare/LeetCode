class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {


        int n=capacity.size();
        int total_full_bags=0;

        for(int i=0;i<n;i++)
        {
            capacity[i]=capacity[i]-rocks[i];
            if(capacity[i]==0)
            {
                total_full_bags++;
            }
        }

        sort(capacity.begin(),capacity.end());

        for(int i=0;i<n;i++)
        {
            if(capacity[i]>0  && additionalRocks>0 && capacity[i]<= additionalRocks)
            {
                total_full_bags++;
                additionalRocks-=capacity[i];
                capacity[i]-=capacity[i];
            }
        }
        
        return total_full_bags;
    }
};