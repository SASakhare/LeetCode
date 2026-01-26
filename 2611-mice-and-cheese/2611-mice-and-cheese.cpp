class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {

        priority_queue<int> pq;
        long long int ans = 0;
        int n = reward2.size();
        for (int i = 0; i < n; i++) {
            pq.push(reward1[i] - reward2[i]);
            ans += reward2[i];
        }

        while (k != 0) {
            ans += pq.top();
            pq.pop();
            k--;
        }

        return ans;
    }
};