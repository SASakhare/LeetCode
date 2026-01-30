class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int n = intervals.size();
        // ------------------------------------------------------------------------------------------
        // sort(intervals.begin(), intervals.end());

        // vector<int> res;

        // for (int i = 0; i < n; i++) {
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     bool isgot_pos = false;
        //     for (int& num : res) {
        //         if (num < start) {
        //             isgot_pos = true;
        //             num = end;
        //             break;
        //         }
        //     }

        //     if (!isgot_pos) {
        //         res.push_back(end);
        //     }
        // }

        // return res.size();

        // -------------------------------------------------------------------------------------------

        unordered_map<int, int> start;
        unordered_map<int, int> end;
        int right_max = 0;

        // vector<int>overlap;

        for (int i = 0; i < n; i++) {
            start[intervals[i][0]]++;
            end[intervals[i][1]]++;
            right_max = max(right_max, intervals[i][1]);
        }

        vector<int> overlap(right_max + 1, 0);
        int res = 0;
        for (int i = 1; i <= right_max; i++) {
            overlap[i] = overlap[i - 1];

            if (start.find(i) != start.end()) {
                overlap[i] += start[i];
            }

            if (end.find(i-1) != end.end()) {
                overlap[i] -= end[i-1];
            }

            res = max(res, overlap[i]);
        }

        return res;
    }
};