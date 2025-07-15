class Solution {
public:
    string intToRoman(int num) {


        unordered_map<int,string>mp;
        mp[1]="I";
        mp[4]="IV";
        mp[5]="V";
        mp[9]="IX";
        mp[10]="X";
        mp[40]="XL";
        mp[50]="L";
        mp[90]="XC";
        mp[100]="C";
        mp[400]="CD";
        mp[500]="D";
        mp[900]="CM";
        mp[1000]="M";

        int num1=num;
        string st="";

        while(num1>0)
        {
            int no_of_digits=log10(num1);

            int last_digit=(num1/pow(10,no_of_digits))  ;
            cout<<last_digit<<" ";
            int new_num=0;
            if(last_digit==4 || last_digit==9 || last_digit==5)
            {
               new_num=last_digit*pow(10,no_of_digits);
                st=st+mp[new_num];
            }
            else if( last_digit/5==1)
            {
                new_num=5*pow(10,no_of_digits);
                st=st+mp[new_num];
                // last_digit-=5;
                new_num=pow(10,no_of_digits);
                for(int i=0;i<(last_digit-5);i++)
                {
                    st=st+mp[new_num];
                }
                new_num=new_num*(last_digit);

            }
            else {

                 new_num=pow(10,no_of_digits);
                for(int i=0;i<last_digit;i++)
                {
                    st=st+mp[new_num];
                }
                new_num=new_num*last_digit;
            }            

            num1=num1-new_num;

        }

        return st;
    }
};