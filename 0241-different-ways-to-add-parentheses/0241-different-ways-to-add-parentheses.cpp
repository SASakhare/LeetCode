class Solution {
public:
    int operation(int n1,int n2,char op)
    {
        if(op=='+')
        {
            return n1+n2;
        }
        else if(op=='-')
        {
            return n1-n2;
        }

        return n1*n2;
    }
    vector<int> diffWaysToCompute(string expression) {

        vector<int>res;
        int n=expression.size();
        if(n==1)
        {
            return {expression[0]-'0'};
        }

        if(n==2)
        {
            return {stoi(expression)};
        }
        for(int i=0;i<n;i++)
        {
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
            {
                vector<int>left=diffWaysToCompute(expression.substr(0,i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1));
                char op=expression[i];

                for(int lt:left)
                {
                    for(int rt:right )
                    {
                        res.push_back(operation(lt,rt,op));
                    }
                }

            }

        }

        return res;        
    }
};