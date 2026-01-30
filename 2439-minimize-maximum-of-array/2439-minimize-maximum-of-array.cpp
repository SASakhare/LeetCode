class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        int n = nums.size();
        //--------------------------------------------------------------------------------
        // bool ops = true;

        // while (ops) {

        //     bool any_ops = false;
        //     for (int i = n - 1; i > 0; i--) {
        //         while (nums[i] > nums[i - 1]) {
        //             nums[i]--;
        //             nums[i - 1]++;
        //             any_ops = true;
        //         }
        //     }

        //     ops = any_ops;
        // }

        // int maxi = 0;
        // for (int i = 0; i < n; i++) {
        //     maxi = max(nums[i], maxi);
        // }
        // return maxi;

        // -------------------------------------------------------------------------------
        // auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        //     if (a.first != b.first)
        //         a.first < b.first;

        //     return a.second > b.second;
        // };
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
        //     pq(cmp);

        // for (int i = 0; i < n; i++) {
        //     pq.push({nums[i], i});
        // }

        // while (!pq.empty()) {
        //     int ele = pq.top().first;
        //     int i = pq.top().second;
        //     pq.pop();

        //     if (i > 0 && nums[i] > nums[i - 1]) {
        //         while (nums[i] > nums[i - 1]) {

        //             nums[i]--;
        //             nums[i - 1]++;
        //         }
        //         pq.push({nums[i], i});
        //         pq.push({nums[i - 1], i - 1});
        //     }
        // }
        // int maxi = 0;
        // for (int i = 0; i < n; i++) {
        //     maxi = max(nums[i], maxi);
        // }
        // return maxi;

    //--------------------------------------------------------------------

    // here we i want distrubute the element to the prefix of array upto i so
        long long res = 0;
        long long sum=0;
        for (int i = 0; i < n; i++) {
            sum+=nums[i];
            res=max(res,(sum+i)/(i+1));
        }
        return res;
    }
};