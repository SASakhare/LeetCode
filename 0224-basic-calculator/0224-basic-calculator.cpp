class Solution {
    private :

    int helper(string & s,int & i)
    {
        int num=0;
        int sign=1;
        int result=0;

        while(i<s.size())
        {   
            char ch=s[i];
            if(isdigit(ch))
            {
                num=num*10 + (ch-'0');

            } else if(ch=='-')
            {
                result+=(num*sign);
                num=0;
                sign=-1;
            }else if(ch=='+')
            {
                result+=(num*sign);
                num=0;
                sign=1;
            }else if(ch=='(')
            {
                i++;
                num=helper(s,i);
            }else if(ch==')')
            {
                result+=num*sign;
                return result;
            }
            i++;
        }
        return  result + num * sign;
    }
public:
    int calculate(string s) {

        int i=0;

        return helper(s,i);
    }
};