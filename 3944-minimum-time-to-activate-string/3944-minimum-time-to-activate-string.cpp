class Solution {

    bool fun(string& s, long long& cnt, int& k, set<int>&st,int pos) {
        // base case :

        auto it=st.lower_bound(pos);
        it--;

        long long before=pos-int(*it);

        it=st.upper_bound(pos);
        long long after=int(*it)-pos;

        cnt+=(before * after);

        if(cnt>=k)
        {
            return true;
        }

        st.insert(pos);
        return false;
    }

public:
    int minTime(string s, vector<int>& order, int k) {

        int n = order.size();
        long long cnt = 0;
        set<int>st={-1,n};

        for (int t = 0; t < n; t++) {
            // map<char, int> mp;
            s[order[t]] = '*';
            if (fun(s, cnt, k,st,order[t])) {
                return t;
            }
        }

        return -1;
    }
};