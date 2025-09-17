// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

//         unordered_set<string>st(wordList.begin(),wordList.end());
//         queue<pair<string,int>> q;
//         q.push(make_pair(beginWord,1));
//         st.erase(beginWord);

//         while(!q.empty())
//         {
//             string word=q.front().first;
//             int cnt=q.front().second;
//             q.pop();

//             if(word==endWord)
//             {
//                 return cnt;
//             }

//             int n=word.size();
//             for(int i=0;i<n;i++)
//             {
//                 char original=word[i];
//                 for(char ch='a';ch<='z';ch++)
//                 {
//                     word[i]=ch;
//                     if(st.find(word)!=st.end())
//                     {
//                         q.push(make_pair(word,cnt+1));
//                         st.erase(word);
//                     }

//                 }

//                 word[i]=original;
//             }

//         }

//         return 0;
//     }
// };


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();

            if(word==endWord) return steps;
            int n=word.size();
            for(int i=0;i<n;i++)
            {
                char orig=word[i];

                for(char ch='a' ;ch<='z';ch++)
                {
                    word[i]=ch;
                    if(s.find(word)!=s.end())
                    {
                        q.push({word,steps+1});
                        s.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        
        return 0;
    }
};