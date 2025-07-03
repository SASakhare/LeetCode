class Solution {
public:
    char kthCharacter(int k) {
        
        string word="a";

        while(word.size()<k)
        {
            //finding the next char string :
            string temp=word;
            int n=word.size();
            for(int i=0;i<n;i++)
            {
                char ch= (temp[i]-'a' + 1 ) % 26 + 'a';
                temp[i]=ch;
            }
            word=word+temp;
        }

        return word[k-1];
    }
};