class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {

        long long n = nums1.size();

        if(k==0)
        {
            for(int i=0;i<n;i++)
            {
                if(nums1[i]!=nums2[i])
                {
                    return -1;
                }
            }

            return 0;
        }

        // int sum=0;
        long long neg_sum = 0;
        long long pos_sum = 0;
        for (int i = 0; i < n; i++) {

            if (abs(nums1[i] - nums2[i]) % k == 0) {
                // sum+(nums2[i]-nums1[i]);
                if ((nums2[i] - nums1[i]) > 0) {
                    pos_sum += (nums2[i] - nums1[i]);// +ve
                } else {
                    neg_sum += (nums2[i] - nums1[i]);// -ve
                }
            } else {
                return -1;
            }
        }

        if (pos_sum + neg_sum != 0) {
            return -1;
        }

        return (pos_sum / k);
    }
};