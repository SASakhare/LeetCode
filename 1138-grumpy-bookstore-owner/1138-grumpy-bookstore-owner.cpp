class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n=customers.size();
        int windSum=0;
        int maxWindSum=0;
        int zeroSum=0;

        for(int i=0;i<n;i++)
        {
            zeroSum+=(grumpy[i]==0 ? customers[i] : 0);

            if(i<minutes)
            {
                windSum+=(grumpy[i]==1 ? customers[i] : 0);
            }else
            {
                windSum+=(grumpy[i]==1 ? customers[i] : 0) - (grumpy[i-minutes]==1 ? customers[i-minutes] : 0);
            }

           maxWindSum=max(maxWindSum,windSum);
        }


        return zeroSum+maxWindSum;
    }
};