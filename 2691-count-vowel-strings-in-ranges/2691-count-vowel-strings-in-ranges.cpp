class Solution {
public:

    bool isValidStr(char ch)
    {
     return   ch == 'a' || ch== 'e'||ch== 'i' ||ch == 'o' || ch== 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>nums(n,0);

        for(int i=0;i<n;i++)
        {
            if(isValidStr(words[i][0]) && isValidStr(words[i].back()))
            {
                nums[i]=1;
            }
            // fiding the prefix sum aswell while checking :
            if(i>0)
            {
                nums[i]=nums[i]+nums[i-1];
            }
        }


        int m=queries.size();
        vector<int>res(m,0);
        for(int i=0;i<m;i++)
        {
            int left=queries[i][0];
            int right=queries[i][1];

            if(left==0)
            {
                res[i]=nums[right];
            }else
            {
                res[i]=nums[right]-nums[left-1];
            }
        }

        return res;
    }
};