// class Solution {
// public:
//     // int mod=1e9+7;
//     // int fun(int ind,int sum,vector<int>&temp,int k,int n)
//     // {
//     //     // base Case :

//     //     if(ind>=n)
//     //     {
//     //         if(sum>=k)
//     //         {
//     //             return 1;
//     //         }else
//     //         {
//     //             return 0;
//     //         }
//     //     }

//     //     if(sum<k)
//     //     {
//     //         return 0;
//     //     }


//     //     // Recursive Case :

//     //     // All pick :
//     //     int pick=fun(ind+1,sum,temp,k,n);

//     //     // reject one :
//     //     int rejectOne=0;
//     //     if(temp[ind]>1)
//     //     {
//     //         temp[ind]--;
//     //         rejectOne=fun(ind,sum-1,temp,k,n);
//     //         temp[ind]++;
//     //     }

//     //     return (pick+rejectOne)%mod;
//     // }

//     // Got TLe :
//     //     int fun(int ind,int sum,vector<int>&temp,int k,int n)
//     // {
//     //     // base Case :

//     //     if(ind>=n)
//     //     {
//     //         if(sum>=k)
//     //         {
//     //             return 1;
//     //         }else
//     //         {
//     //             return 0;
//     //         }
//     //     }

//     //     // Recursive Case :

//     //     long long res = 0;

//     //     // Try picking 1 to temp[ind] characters from this group
//     //     for (int take = 1; take <= temp[ind]; ++take) {
//     //         res = (res + fun(ind + 1, sum + take, temp, k, n)) % mod;
//     //     }

//     //     return res;
//     // }

//     // int possibleStringCount(string word, int k) 
//     // {   
//     //     int n=word.size();
//     //     vector<int>temp;

//     //     // finding the consecutive occurence of the one char :
//     //     int i=0,j=0;
//     //     while(i<n)
//     //     {
//     //         while(j<n && word[i]==word[j])
//     //             j++;
//     //         temp.push_back(j-i);
//     //         i=j;
//     //     }

//     //     // sum=n;
//     //     int m=temp.size();

//     //     return fun(0,0,temp,k,m);// fun(index,sum,temp,k,n)    
//     // }



// // Memoization Soltuion : Got TLE 
//     //  int mod = 1e9 + 7;
//     // vector<vector<int>> dp;

//     // int fun(int ind, int sum, vector<int>& temp, int k, int n) {
//     //     if (ind >= n) {
//     //         return (sum >= k) ? 1 : 0;
//     //     }

//     //     if (dp[ind][sum] != -1) return dp[ind][sum];

//     //     long long res = 0;
//     //     for (int take = 1; take <= temp[ind]; ++take) {
//     //         res = (res + fun(ind + 1, sum + take, temp, k, n)) % mod;
//     //     }

//     //     return dp[ind][sum] = res;
//     // }

//     // int possibleStringCount(string word, int k) {
//     //     int n = word.size();
//     //     vector<int> temp;

//     //     // Group consecutive characters
//     //     for (int i = 0; i < n;) {
//     //         int j = i;
//     //         while (j < n && word[i] == word[j]) j++;
//     //         temp.push_back(j - i);
//     //         i = j;
//     //     }

//     //     int m = temp.size();

//     //     // Max possible sum = length of word
//     //     dp.assign(m + 1, vector<int>(n + 1, -1));

//     //     return fun(0, 0, temp, k, m);
//     // }


//     // Tabulation Method : 


//     //    int mod = 1e9 + 7;

//     // int possibleStringCount(string word, int k) {
//     //     int n = word.size();
//     //     vector<int> groupLens;

//     //     // Step 1: Group consecutive characters
//     //     for (int i = 0; i < n;) {
//     //         int j = i;
//     //         while (j < n && word[j] == word[i]) j++;
//     //         groupLens.push_back(j - i);
//     //         i = j;
//     //     }

//     //     int m = groupLens.size(); // number of groups

//     //     // Step 2: Initialize DP table
//     //     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//     //     dp[0][0] = 1;  // Base case: 0 groups used, 0 characters picked

//     //     // Step 3: Fill DP table
//     //     for (int i = 1; i <= m; ++i) {
//     //         int len = groupLens[i - 1];  // Current group length

//     //         for (int prevLen = 0; prevLen <= n; ++prevLen) {
//     //             if (dp[i - 1][prevLen] == 0) continue;

//     //             for (int take = 1; take <= len; ++take) {
//     //                 if (prevLen + take <= n) {
//     //                     dp[i][prevLen + take] = (dp[i][prevLen + take] + dp[i - 1][prevLen]) % mod;
//     //                 }
//     //             }
//     //         }
//     //     }

//     //     // Step 4: Sum all valid lengths >= k
//     //     int ans = 0;
//     //     for (int len = k; len <= n; ++len) {
//     //         ans = (ans + dp[m][len]) % mod;
//     //     }

//     //     return ans;
//     // }

//     // int mod = 1e9 + 7;

//     // int possibleStringCount(string word, int k) {
//     //     int n = word.size();
//     //     vector<int> groupLens;

//     //     // Group consecutive characters
//     //     for (int i = 0; i < n;) {
//     //         int j = i;
//     //         while (j < n && word[j] == word[i]) j++;
//     //         groupLens.push_back(j - i);
//     //         i = j;
//     //     }

//     //     // Initialize DP with 0
//     //     vector<int> dp(n + 1, 0);
//     //     dp[0] = 1; // 0 groups used, 0 length

//     //     for (int groupSize : groupLens) {
//     //         vector<int> new_dp(n + 1, 0);

//     //         for (int prevLen = 0; prevLen <= n; ++prevLen) {
//     //             if (dp[prevLen] == 0) continue;

//     //             // Pick 1 to groupSize characters
//     //             for (int take = 1; take <= groupSize && prevLen + take <= n; ++take) {
//     //                 new_dp[prevLen + take] = (new_dp[prevLen + take] + dp[prevLen]) % mod;
//     //             }
//     //         }

//     //         dp = move(new_dp); // Replace old with new
//     //     }

//     //     // Sum all combinations of length ≥ k
//     //     int ans = 0;
//     //     for (int len = k; len <= n; ++len) {
//     //         ans = (ans + dp[len]) % mod;
//     //     }

//     //     return ans;
//     // }

//     // int mod = 1e9 + 7;

//     // int possibleStringCount(string word, int k) {
//     //     int n = word.size();
//     //     vector<int> groupLens;

//     //     // Group consecutive characters
//     //     for (int i = 0; i < n;) {
//     //         int j = i;
//     //         while (j < n && word[j] == word[i]) j++;
//     //         groupLens.push_back(j - i);
//     //         i = j;
//     //     }

//     //     // Initialize DP
//     //     vector<int> dp(n + 2, 0);  // +2 to prevent index overflow
//     //     dp[0] = 1;

//     //     for (int groupSize : groupLens) {
//     //         vector<int> new_dp(n + 2, 0);

//     //         for (int len = 0; len <= n; ++len) {
//     //             if (dp[len] == 0) continue;

//     //             int l = len + 1;
//     //             int r = len + groupSize + 1;

//     //             if (l <= n) {
//     //                 new_dp[l] = (new_dp[l] + dp[len]) % mod;
//     //                 if (r <= n)
//     //                     new_dp[r] = (new_dp[r] - dp[len] + mod) % mod;
//     //             }
//     //         }

//     //         // Build prefix sum for new_dp
//     //         for (int i = 1; i <= n; ++i) {
//     //             new_dp[i] = (new_dp[i] + new_dp[i - 1]) % mod;
//     //         }

//     //         dp = move(new_dp);
//     //     }

//     //     // Final result: sum of dp[len] for all len >= k
//     //     int ans = 0;
//     //     for (int len = k; len <= n; ++len) {
//     //         ans = (ans + dp[len]) % mod;
//     //     }

//     //     return ans;

//     // }

//         int mod = 1e9 + 7;

//     int possibleStringCount(string word, int k) {
//         int n = word.size();
//         vector<int> groupLens;

//         // Step 1: Group characters
//         for (int i = 0; i < n;) {
//             int j = i;
//             while (j < n && word[i] == word[j]) j++;
//             groupLens.push_back(j - i);
//             i = j;
//         }

//         // Step 2: Initialize DP with only 0-length string
//         unordered_map<int, int> dp;
//         dp[0] = 1;

//         for (int groupSize : groupLens) {
//             unordered_map<int, int> new_dp;

//             for (auto& [len, count] : dp) {
//                 for (int take = 1; take <= groupSize; ++take) {
//                     int newLen = len + take;
//                     new_dp[newLen] = (new_dp[newLen] + count) % mod;
//                 }
//             }

//             dp = move(new_dp);
//         }

//         // Step 3: Sum all lengths ≥ k
//         int ans = 0;
//         for (auto& [len, count] : dp) {
//             if (len >= k)
//                 ans = (ans + count) % mod;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    int possibleStringCount(string& word, int k) {
        int n = (int)word.size();
        if (n < k) return 0;
        if (n == k) return 1;

        // 1) Build consecutive segments
        vector<int> segs;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;
            segs.push_back(j - i);
            i = j;
        }

        int m = (int)segs.size();

        // 2) Calculate total ways (product of seg lengths)
        long long total = 1;
        bool tookMod = false;
        for (int x : segs) {
            total *= x;
            if (total >= mod) {
                total %= mod;
                tookMod = true;
            }
        }

        if (total == 1 && !tookMod) return 1;  // special case all 1-length segments
        if (k <= m) return (int)total;

        // 3) Use DP + prefix sums to count invalid strings with length < k

        // z_i = number picked from seg_i minus 1
        // sum z_i <= k - m - 1, and 0 <= z_i <= seg_i - 1

        int maxT = k - m - 1;

        vector<vector<long long>> dp(2, vector<long long>(maxT + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            int s = segs[i];
            vector<long long> prefix(maxT + 2, 0);
            for (int len = 0; len <= maxT; len++) {
                prefix[len + 1] = (prefix[len] + dp[i & 1][len]) % mod;
            }
            for (int len = 0; len <= maxT; len++) {
                int L = max(0, len - (s - 1));
                int R = len;
                dp[(i + 1) & 1][len] = (prefix[R + 1] - prefix[L] + mod) % mod;
            }
        }

        long long lessK = 0;
        for (auto x : dp[m & 1]) lessK = (lessK + x) % mod;

        return (total - lessK + mod) % mod;
    }
};
