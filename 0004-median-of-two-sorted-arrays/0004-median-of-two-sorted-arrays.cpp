class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int l0 = 0, hi = m;

        while (l0 <= hi) {
            int i = (l0 + hi) / 2;
            int j = (m + n + 1) / 2 - i;
            int l1 = i ? nums1[i - 1] : INT_MIN;
            int r1 = i < m ? nums1[i] : INT_MAX;

            int l2 = j ? nums2[j - 1] : INT_MIN;
            int r2 = j < n ? nums2[j] : INT_MAX;

            if (l1 > r2) {
                hi = i - 1;
            } else if (l2 > r1) {
                l0 = i + 1;
            } else {

                return (m + n) % 2 ? max(l1, l2)
                                   : (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }

        return 0;
    }
};