class Solution {
public:
    bool isValid(string s) {

        stack<char> bracket;
        int N = s.size();
        for (int i = 0; i < N; i++) 
        {
            int c=s[i];
            if((c=='(') || (c=='[') || (c=='{'))
            {
                bracket.push(c);
            }
            else if(!bracket.empty())
            {
                int h=bracket.top();
                bracket.pop();
                if((c==')' && h=='(') || (c==']' && h=='[') || (c=='}' && h=='{'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        
        
        }
        if(bracket.empty())
        {
            return true;
        }
        return false;
    }
};