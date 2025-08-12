class Solution {
public:
    int fillCups(vector<int>& amount) {
        
        int cnt=0;
        priority_queue<int>pq;
        for(int i=0;i<3;i++)
        {
            pq.push(amount[i]);
        }

        while(pq.size()>1)
        {
            int cup1=pq.top();
            pq.pop();
            int cup2=pq.top();
            pq.pop();
            if(cup1 > 0 || cup2 >0)
                cnt++;
            cup1--;
            cup2--;
            if(cup1>0)
                pq.push(cup1);
            if(cup2>0)
                pq.push(cup2);
        }
        
        if(pq.size()==1)
        {
            cnt+=pq.top();
            pq.pop();
        }

        return  cnt;
    }

};