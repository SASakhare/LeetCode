class Solution {
public:
    void nextPermutation(vector<int>& permutation) {
        int index = -1;
        int n = permutation.size();

        for (int i = n - 2; i >= 0; i--) {
            if (permutation[i] < permutation[i + 1]) {
                index = i;
                break;
            }
        }

        // find the beggest smallest element.

        if (index != -1) {

            for (int i = n - 1; i >= 0; i--) {
                if (permutation[i] > permutation[index]) {
                    swap(permutation[i], permutation[index]);
                    break;
                }
            }

            reverse(permutation.begin() + index + 1, permutation.end());
        } else {

            reverse(permutation.begin(), permutation.end());
            // return permutation;
            return;
        }

        // return permutation;
        return;
    }
};