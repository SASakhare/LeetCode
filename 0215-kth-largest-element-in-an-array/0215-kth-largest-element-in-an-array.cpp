class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //* 1st Approach:
    //     int n=nums.size();
    //     stack<int>st;
    //     stack<int>temp;

    //     for(int i=0;i<n;i++)
    //     {
    //         if(st.empty())
    //         {
    //             st.push(nums[i]);
    //         }
    //         else
    //         {

    //             while(!st.empty() && st.top()>nums[i])
    //             {
    //                 temp.push(st.top());
    //                 st.pop();
    //             }
    //             temp.push(nums[i]);
    //             while(temp.size()>k)
    //             {
    //                 temp.pop();
    //             }
    //             while(!temp.empty())
    //             {
    //                 st.push(temp.top());
    //                 temp.pop();
    //             }
    //         }

    //     }
    //     while(k>1 && !st.empty())
    //     {
    //         k--;
    //         st.pop();
    //     }

    // return st.top();

    // 2nd Approach :  Priority _Queue

    priority_queue<int,  vector<int>, greater<int>> pq;
    // priority_queue <int, vector<int>, greater<int>> gq;

    int n=nums.size();
    for(int i=0;i<n;i++)
    {

        pq.push(nums[i]);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }

  
return  pq.top(); 
    }
};