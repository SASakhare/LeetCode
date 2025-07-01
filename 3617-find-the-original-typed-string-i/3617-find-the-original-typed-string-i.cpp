class Solution {
public:
    int possibleStringCount(string word) {

        // int count = 1;
        // int n = word.size();
        // vector<int> v(26, 0);
        // vector<bool> consecutive(26, true);
        // int prevIndex = int(word[0]) - int('a');
        // // consecutive[prevIndex]=true;
        // for (int i = 0; i < n; i++) {
        //     int index1 = int(word[i]) - int('a');
        //     if (prevIndex == index1 || consecutive[index1]) {
        //         v[index1] += 1;
        //         if (prevIndex != index1)
        //         {
        //             consecutive[prevIndex] = false;
        //             prevIndex=index1;
        //         }
        //         else
        //         {
        //             consecutive[prevIndex] = true;
        //             prevIndex=index1;
        //         }
                    
        //     }
        //     else
        //         {
        //             consecutive[prevIndex] = false;
        //             prevIndex=index1;
        //         }
        // }
        // n = v.size();

        // for (int i = 0; i < n; i++) {
        //     if (v[i] != 0) {
        //         v[i] = v[i] - 1;
        //         count += v[i];
        //     }
        // }

        // return count;


        // Another Method :

        int n=word.size();
        int count=1;
        char prev=word[0];
        for(int i=1;i<n;i++)
        {
            if(prev==word[i])
            {
                count++;
            }
            prev=word[i];
        }


        return count;

    }
};