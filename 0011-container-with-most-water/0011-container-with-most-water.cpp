class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        int totalWater=0;
        int low=0;
        int high=n-1;

        while(low<n && high>0 && low<=high)
        {
            int water_amt=(high-low) * min(height[low],height[high]);

            if(water_amt>totalWater)
            {
                totalWater=water_amt;
            }
            
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }

        }


        return totalWater;
    }
};