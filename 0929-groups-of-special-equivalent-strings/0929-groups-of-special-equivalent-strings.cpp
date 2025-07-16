class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {

        set<vector<int>>st;
        int n=words.size();
        int m=words[0].size();

        // traversing the words array
        for(int i=0;i<n;i++)
        {
            // traversing the each word in words:
            string word=words[i];
            vector<int>temp(52,0);// first 26 even and after 26 odd.
            for(int j=0;j<m;j++)
            {
                char ch=word[j];
                int index=ch-'a';

                // if odd then it shifted 26 forward
                if(j%2==1)
                {
                    index+=26;
                }
                temp[index]++;
            }

            st.insert(temp);
        }

        return st.size();
    }
};