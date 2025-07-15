class Solution {
public:
    string entityParser(string text) {
        

        unordered_map<string,string>mp;
        mp["&quot;"]="\"";
        mp["&apos;"]="'";
        mp["&amp;"]="&";
        mp["&gt;"]=">";
        mp["&lt;"]="<";
        mp["&frasl;"]="/";

        int n=text.size();
        vector<int>occur;

        for(int i=0;i<n;i++)
        {
            if(text[i]=='&')
            {
                occur.push_back(i);
            }
        }


        int m=occur.size();

        string res="";
        int ind=0;
        for(int i=0;i<m;i++)
        {
            int index=occur[i];

            while(ind<index & ind<n)
            {
                res+=text[ind];
                ind++;
            }

            string word="";
            while(index<n && text[index]!=';')
            {
                    word+=text[index];
                    index++;
            }

            word+=';';
            // index++;

            if(mp.find(word)!=mp.end())
            {
                // res+=mp[word];
                // text.replace(occur[i],word.size(),mp[word]);
                res+=mp[word];
                ind=index+1;
                
            }

        }

        while(ind<n)
        {
            res+=text[ind];
            ind++;
        }
        return res;
    }
};