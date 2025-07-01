class Solution {
public:
    string reversePrefix(string word, char ch) {

        // Using Stack :

        // int n = word.size();
        // string copy = word;
        // string R = "";
        // bool found = false;
        // stack<char> st;
        // int i = 0;
        // for (i = 0; i < n; i++) {
        //     if (!found) {
        //         if (copy[i] == ch) {
        //             found = true;
        //         }
        //         st.push(copy[i]);
        //     }
        //     else{
        //         break;
        //     }
        // }

        // while(!st.empty()) {
        //     R += st.top();
        //     st.pop();
        // }
        // while (i < n) {
        //     R += word[i];
        //     i++;
        // }

        // if (found && st.empty()) {
        //     return R;
        // }
        // return word;


        // Using Two pointer :

        int n=word.size();
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            if(word[i]==ch)
            {
                ind=i;
                break;
            }
        }

        if(ind==-1)
        {
            return word;
        }
        string s=word;

        int low=0;
        int high=ind;
        while(low<=high)
        {
            swap(s[low],s[high]);
            low++;
            high--;
        }

        return s;
    }
};