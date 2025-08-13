class Solution {
public:
    string frequencySort(string s) {

    //  int n=s.size();
    //  unordered_map<char,int>mp;
    //  for(int i=0;i<n;i++)
    //  {
    //     mp[s[i]]++;
    //  }   

    //  vector< pair<char,int>> vec(mp.begin(),mp.end());

    //  sort(vec.begin(),vec.end(),[](const auto & a,const auto &b)
    //  {
    //     return a.second >b.second;
    //  });

    //     string res="";

    //     // travavering through the vector of the paris.
    //     for(auto &[key,value] : vec )
    //     {
    //         // res+=key;
    //         for(int i=1;i<=value;i++)
    //         {
    //             res+=key;
    //         }
    //     }

    //     return res;

    // Using Max Heap : 

    int n=s.size();
    unordered_map<char,int>mp;
    // finding the freq of each element in the string :
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
    }

    // pushing the element in the heap , max freq way (ie. max heap)
    priority_queue<pair<int,char>>p;

    for(auto it:mp)
    {
        p.push(make_pair(it.second,it.first));
    }

    // taking out each element form the heap :

    string res="";

    while(!p.empty())
    {
        auto it = p.top();
        p.pop();
        for(int i=0;i<it.first;i++)
        {
            res.push_back(it.second);
        }
    }

    return res;

    }
};