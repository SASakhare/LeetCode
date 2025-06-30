class Solution {
public:
    int minimumRefill(vector<int>& plants, int maxA_cap, int maxB_cap) {

        int n=plants.size();
        int capA=maxA_cap;
        int capB=maxB_cap;
        int A=0;
        int B=n-1;
        int res=0;

        while(A<=B)
        {
            // Alice and Bob both are at the same position :
            if(A==B)
            {
                if(capA>=capB)
                {
                        if(capA<plants[A])
                        {
                            res++;
                            capA=maxA_cap;
                        }
                        capA=capA-plants[A];
                        A++;
                }
                else
                {
                        if(capB<plants[B])
                        {
                            res++;
                            capB=maxB_cap;
                        }
                        capB=capB-plants[B];
                        B--;
                }
            }
            else
            {

                if(capA<plants[A])
                {
                    res++;
                    capA=maxA_cap;
                }
                capA=capA-plants[A];
                A++;


            
                if(capB<plants[B])
                {
                    res++;
                    capB=maxB_cap;
                }
                capB=capB-plants[B];
                B--;

            }


        }


        return res;

        
    }
};