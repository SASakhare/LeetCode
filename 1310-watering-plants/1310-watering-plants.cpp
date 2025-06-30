class Solution {
public:
    int wateringPlants(vector<int>& plants, int max_cap) {
        
        int cap=max_cap;
        int i=-1;
        int steps=0;
        int n=plants.size();

        while(i<n-1)
        {
            i++;
            steps++;
            cap=cap-plants[i];

            if(i+1<n && cap<plants[i+1])
            {
                cap=max_cap;
                steps=steps + ((i+1) * 2 );
            }

        }

        return steps;
    }
};